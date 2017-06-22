#include "cachesimulator.h"
#include <cstring>
#include <cstdlib>
#include <vector>

double uniformRandom(double a, double b) {
    return a + (b - a) * (double(rand()) / double(RAND_MAX));
}

int numBits(int n) {
    if(n == 0)
        return 1;
    return log2(n);
}

CacheSimulationParameters::CacheSimulationParameters(int pointerSize/*in bits*/,
                          int lineSize,
                          int numSets,
                          int numWays,
                          CACHE_TYPE type,
                          REPLACEMENT_POLICY replacementPolicy)
{
    this->pointerSize = pointerSize;
    this->lineSize = lineSize;
    this->numSets = numSets;
    this->numWays =  numWays;
    this->type = type;
    this->replacementPolicy =  replacementPolicy;
    this->numOffsetBits = numBits(lineSize);
    this->numSetBits = numBits(numSets);
    this->numTagBits = pointerSize - numSetBits - numOffsetBits;
    tagMask = createMask(numOffsetBits + numSetBits,pointerSize);
    setMask = createMask(numOffsetBits, numOffsetBits + numSetBits);
    offsetMask = createMask(0, numOffsetBits);
}

unsigned CacheSimulationParameters::createMask(unsigned a, unsigned b) {
    unsigned mask = 0;
    for (unsigned i = a; i < b; i++) {
        mask |= 1 << i;
    }
    return mask;
}

struct Line {
    unsigned tag;
    unsigned age;
    unsigned uses;
};

struct Set {
    std::vector<Line> lines;
};

int randomIndex(Set &set) {
    return rand() % set.lines.size();
}

int LFUIndex(Set &set) {
    unsigned min = set.lines[0].uses;
    int minIndex = 0;
    for(size_t i = 1; i < set.lines.size(); i++) {
        if(set.lines[i].age < min)
            minIndex = i;
    }
    return minIndex;
}

int LRUIndex(Set &set) {
    unsigned min = set.lines[0].age;
    int minIndex = 0;
    for(size_t i = 1; i < set.lines.size(); i++) {
        if(set.lines[i].age < min)
            minIndex = i;
    }
    return minIndex;
}

void replace(Set &set, unsigned tag)
{
    int r = randomIndex(set);
    set.lines[r].tag = tag;
    set.lines[r].age = 0;
    set.lines[r].uses = 0;
}

class Cache {
public:
    Cache(CacheSimulationParameters p, std::vector<unsigned> trace) : parameters(p) {
        this->trace = trace;

        sets.resize(p.getNumSets());
        for(size_t i = 0; i < sets.size(); i++)
            sets[i].lines.resize(p.getNumWays());
        hits = 0;
        misses = 0;
    }
    void simulate() {
        for(size_t i = 0; i < trace.size(); i++) {
            access(trace[i]);
        }
    }

    void access(unsigned address) {
        unsigned set = parameters.getSet(address);
        unsigned tag = parameters.getTag(address);
        for(size_t j = 0; j < sets[set].lines.size(); j++) {
            sets[set].lines[j].age++;
        }
        for(size_t i = 0; i < sets[set].lines.size(); i++) {
            if(sets[set].lines[i].tag == tag) {
                sets[set].lines[i].age--;
                sets[set].lines[i].uses++;
                hits++;
                return;
            }
        }

        misses++;
        replace(sets[set], tag);
    }

    int getHits() const { return hits; }
    int getMisses() const { return misses; }
    int getAccesses() const { return hits + misses; }
    double getHitRatio() { return double(hits) / double(getAccesses()); }
    double getMissRatio() { return double(misses) / double(getAccesses()); }
protected:
    CacheSimulationParameters parameters;
    std::vector<unsigned> trace;
    std::vector<Set> sets;
    int hits;
    int misses;
};



CacheSimulator::CacheSimulator()
{

}

void CacheSimulator::runSimulation(CacheSimulationParameters parameters) {

    Cache cache(parameters, trace);
    cache.simulate();

    CacheSimulationResults results;
    results.numAccesses = cache.getAccesses();
    results.hitRatio = cache.getHitRatio();
    results.missRatio = cache.getMissRatio();
    results.compulsoryMissRatio = uniformRandom(0, 1);

    emit resultsChanged(results);
}
