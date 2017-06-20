#include "cachesimulator.h"
#include <cstring>

CacheSimulator::CacheSimulator()
{

}

void CacheSimulator::runSimulation(CacheSimulationParameters parameters) {
    // the actual program that does stuff goes here
    emit resultsChanged(CacheSimulationResults());
}
