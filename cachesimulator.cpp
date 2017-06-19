#include "cachesimulator.h"
#include <cstring>

CacheSimulator::CacheSimulator(int pointerSize, // in bits
                               int lineSize,
                               int numBlocks,
                               int numWays,
                               CACHE_TYPE type,
                               REPLACEMENT_POLICY replacementPolicy,
                               unsigned long *trace,
                               int traceSize)
{
    this->pointerSize = pointerSize;
    this->lineSize = lineSize;
    this->numBlocks = numBlocks;
    this->numWays = numWays;
    this->type = type;
    this->replacementPolicy = replacementPolicy;
    std::memcpy(this->trace, trace, traceSize * sizeof(unsigned long));
    this->traceSize = traceSize;
}
