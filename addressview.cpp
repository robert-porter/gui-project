#include "addressview.h"

const int W = 8;
const int H = 20;

AddressView::AddressView(QWidget *parent) :QWidget(parent) {
    numOffsetBits = 0;
    numTagBits =  0;
    numSetBits = 0;
    numBits = 32;
}

void AddressView::paintEvent(QPaintEvent *)
{
    const QColor tagColor = QColor(255, 0, 0);
    const QColor setColor = QColor(0, 255, 0);
    const QColor offsetColor = QColor(0, 0, 255);


    int offset = 0;

    QPainter painter;
    painter.begin(this);

    painter.setBrush(tagColor);
    for(int i = 0; i < numBits - numSetBits - numOffsetBits; i++) {
        painter.drawRoundedRect(W*i, 0, W, H, 3.0f, 3.0f);
    }
    offset = W * (numBits - numSetBits - numOffsetBits);
    painter.setBrush(setColor);
    for(int j = 0; j < numSetBits; j++) {
        painter.drawRoundedRect(offset + W*j, 0, W, H, 3.0f, 3.0f);
    }
    offset = W* (numBits - numOffsetBits);
    painter.setBrush(offsetColor);
    for(int k = 0; k < numOffsetBits; k++) {
        painter.drawRoundedRect(offset + W*k, 0, W, H, 3.0f, 3.0f);
    }
    painter.end();
}

QSize AddressView::sizeHint() const {
    return QSize(W*numBits, 20);
}

void AddressView::setNumOffsetBits(int n) {
    numOffsetBits = n;
    update();
}

void AddressView::setNumSetBits(int n) {
    numSetBits = n;
    update();
}



