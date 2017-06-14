#ifndef CACHECONTROLLER_H
#define CACHECONTROLLER_H

#include <QObject>

struct Cache {
    int size;
    int lineSize;
    int numLines;
    unsigned long long pointerSize;
    unsigned long long memorySize;
};

class CacheController : public QObject {
    Q_OBJECT
public:
    Cache cache;

public slots:
    void setPointerSize(int value);

signals:
    void pointerSizeChanged(int newValue);
    void memorySizeChanged(QString newValue);
};

#endif // CACHECONTROLLER_H
