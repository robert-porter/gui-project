#ifndef CACHESIMULATOR_H
#define CACHESIMULATOR_H

#include <QObject>
#include <cmath>
#include <vector>
#include <cstring>

enum CACHE_TYPE {
    INSTRUCTION_CACHE = 0,
    DATA_CACHE = 1
};

enum REPLACEMENT_POLICY {
    LFU = 0,
    LRU = 1,
    RANDOM = 2
};

struct CacheSimulationParameters {
public:
    CacheSimulationParameters(int pointerSize/*in bits*/,
                              int lineSize,
                              int numSets,
                              int numWays,
                              CACHE_TYPE type,
                              REPLACEMENT_POLICY replacementPolicy);

    unsigned createMask(unsigned a, unsigned b);
    unsigned getTag(unsigned address) const { return (address & tagMask) >> (numOffsetBits + numSetBits); }
    unsigned getSet(unsigned address) const { return (address & setMask) >> numOffsetBits; }
    unsigned getOffset(unsigned address) const { return address & offsetMask; }
    int getNumSets() const { return numSets; }
    int getNumWays() const { return numWays; }
protected:
    int pointerSize; // in bits
    int lineSize;
    int numSets;
    int numWays;
    CACHE_TYPE type;
    REPLACEMENT_POLICY replacementPolicy;
    int numTagBits;
    int numSetBits;
    int numOffsetBits;
    unsigned tagMask;
    unsigned setMask;
    unsigned offsetMask;
protected:

};

struct CacheSimulationResults {
    int numAccesses;
    float hitRatio;
    float compulsoryMissRatio;
    float missRatio;
};

class CacheSimulator : public QObject
{
    Q_OBJECT
public:
    CacheSimulator();
public slots:
    void setTrace(std::vector<QString> traceStrings) {
        for(int i = 0; i < traceStrings.size(); i++)
            trace.push_back(strtol(traceStrings[i].toLocal8Bit().constData(), 0, 16));
    }
    void runSimulation(CacheSimulationParameters parameters); // emits results
signals:
    void resultsChanged(CacheSimulationResults results);

protected:
    std::vector<unsigned> trace;
};

#endif // CACHESIMULATOR_H
