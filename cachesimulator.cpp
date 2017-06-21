#include "cachesimulator.h"
#include <cstring>
#include <cstdlib>


double uniformRandom(double a, double b) {
    return a + (b - a) * (double(rand()) / double(RAND_MAX));
}

CacheSimulator::CacheSimulator()
{

}

void CacheSimulator::runSimulation(CacheSimulationParameters parameters) {
    // the actual program that does stuff goes here
    CacheSimulationResults results;
    results.numAccesses = rand();
    results.hitRatio = uniformRandom(0,1);
    results.missRatio = uniformRandom(0, 1);
    results.compulsoryMissRatio = uniformRandom(0, 1);

    emit resultsChanged(results);
}
