#ifndef BITSLIDER_H
#define BITSLIDER_H

#include <QWidget>
#include <QSlider>


class BitSlider : public QWidget {
    Q_OBJECT
public:
    BitSlider(QWidget *parent, bool memory);
    void setPointerRange(int a, int b) { slider->setRange(a, b); }
    int getPointerSize() const { return pointerSize; }
public slots:
    void setPointerSize(int value);
signals:
    void memorySizeChangedString(QString newValue);
    void memorySizeChanged(int n);
    void pointerSizeChanged(int n);
private:
    int pointerSize;
    QSlider *slider;
};


#endif // BITSLIDER_H
