#include "CacheController.h"

QString binaryPrefix(unsigned long long x) {
    if(x < 1024)
        return QString::number(x) + QString("B");
    else if(x >= 1024 && x < 1048576)
        return QString::number(x / 1024) + QString("KB");
    else if(x >= 1048576 && x < 1073741824)
        return QString::number(x / 1048576) + QString("MB");
    else
        return QString::number(x / (unsigned long)(1073741824)) + QString("GB");
}



void CacheController::setPointerSize(int value)
{
    if (cache.pointerSize != value) {
        cache.pointerSize = value;
        cache.memorySize = static_cast<unsigned long long>(1) << cache.pointerSize;
        emit pointerSizeChanged(value);
        emit memorySizeChanged(binaryPrefix(cache.memorySize));
    }
}

