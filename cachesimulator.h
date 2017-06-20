#ifndef CACHESIMULATOR_H
#define CACHESIMULATOR_H

#include <QObject>

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
    int pointerSize; // in bits
    int lineSize;
    int numSets;
    int numWays;
    CACHE_TYPE type;
    REPLACEMENT_POLICY replacementPolicy;
    unsigned long *trace;
    int traceSize;
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
    void runSimulation(CacheSimulationParameters parameters); // emits results
signals:
    void resultsChanged(CacheSimulationResults results);
};

#endif // CACHESIMULATOR_H
