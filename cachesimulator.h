#ifndef CACHESIMULATOR_H
#define CACHESIMULATOR_H


enum CACHE_TYPE {
    INSTRUCTION_CACHE,
    DATA_CACHE
};

enum REPLACEMENT_POLICY {
    LFU,
    LRU,
    RANDOM
};

class CacheSimulator
{
public:
    CacheSimulator(int pointerSize, // in bits
    int lineSize,
    int numBlocks,
    int numWays,
    CACHE_TYPE type,
    REPLACEMENT_POLICY replacementPolicy,
    unsigned long *trace,
    int traceSize);

protected:
    //inputs
    int pointerSize; // in bits
    int lineSize;
    int numBlocks;
    int numWays;
    CACHE_TYPE type;
    REPLACEMENT_POLICY replacementPolicy;
    unsigned long *trace;
    int traceSize;

    //outputs

};

#endif // CACHESIMULATOR_H
