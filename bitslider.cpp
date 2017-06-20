#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <stdlib.h>
#include "bitslider.h"


void fixLabelSize(QLabel *l, int n) {
    // kind of a hack, fill label with n "M"s, since M is "wide",
    // then fix the size and then empty the text

    QString ms = "";
    ms.fill('M', n);

    l->setText(ms);
    QSize s = l->sizeHint();
    l->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    l->setFixedSize(s);
    l->setText("");
}

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

BitSlider::BitSlider(QWidget *parent, bool memory) : QWidget(parent) {
    QLayout *layout = new QHBoxLayout();
    setLayout(layout);

    slider = new QSlider(Qt::Horizontal, 0);
    slider->setRange(0, 32);

    QLabel *label = new QLabel(0);
    fixLabelSize(label, 5);

    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setPointerSize(int)));

    if(memory) {
        QObject::connect(this, SIGNAL(memorySizeChangedString(QString)), label, SLOT(setText(QString)));
        label->setText("2B");
    }
    else {
        QObject::connect(this, SIGNAL(memorySizeChanged(int)), label, SLOT(setNum(int)));
        label->setText("1");
    }
    layout->addWidget(label);
    layout->addWidget(slider);
}

void BitSlider::setPointerSize(int value)
{
    if (pointerSize != value) {
        pointerSize = value;
        slider->setValue(value);
        unsigned long long memorySize = static_cast<unsigned long long>(1) << pointerSize;
        emit memorySizeChangedString(binaryPrefix(memorySize));
        emit memorySizeChanged(memorySize);
        emit pointerSizeChanged(pointerSize);
    }
}
