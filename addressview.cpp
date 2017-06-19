#include "addressview.h"

const int W = 8;
const int H = 20;

AddressView::AddressView(QWidget *parent) :QWidget(parent) {
    numOffsetBits = 0;
    numSetBits = 0;
    numBits = 32;
    setMinimumSize(sizeHint());
}

void AddressView::drawBitBlock(QPainter &painter, int xStart, int numBits, int blockIndex, QColor color, QString text, int widgetWidth) {

    int textTop = H + 15;
    int textHeight = H;
    int textLeft = widgetWidth * blockIndex / 3;
    int labelLineStartX = widgetWidth * (1 + 2 * blockIndex) / 6;
    int heightOffset = 2 + blockIndex * 4;
    int labelLineDestX = xStart + (W * numBits) / 2;

    painter.setBrush(color);
    for(int i = 0; i < numBits; i++) {
        painter.drawRoundedRect(xStart + W*i, 0, W, H, 3.0f, 3.0f);
    }

    QFont font=painter.font() ;
    font.setStyleStrategy(QFont::NoAntialias);
    painter.setFont(font);
    painter.drawText(textLeft, textTop, widgetWidth / 3, textHeight, Qt::AlignCenter, text + QString("(") + QString::number(numBits) + QString(")"));
    if(numBits <= 0) // don't draw label line if no bits
        return;
    painter.drawLine(QPointF(labelLineStartX, textTop), QPointF(labelLineStartX, textTop - heightOffset));
    painter.drawLine(QPointF(labelLineStartX, textTop - heightOffset), QPointF(labelLineDestX, textTop - heightOffset));
    painter.drawLine(QPointF(labelLineDestX, textTop - heightOffset), QPointF(labelLineDestX, H));

}

void AddressView::drawPointerSizeLabel(QPainter &painter, int numBits) {
    int y = H + H + 15; //TODO: s

    for(int i = 0; i < 3; i++) {
        int labelLineStartX = width() * (1 + 2 * i) / 6;
        painter.drawLine(QPointF(labelLineStartX, y), QPointF(labelLineStartX, y + 5));
        painter.drawLine( QPointF(labelLineStartX, y + 5), QPointF(width() / 2, y + 5));
    }

    painter.drawLine(QPointF(width() / 2 + 5, y + 5), QPointF(width() / 2 + 5, y + 10));
    painter.drawText(0, y + 10, width(), H, Qt::AlignCenter, "Pointer size" + QString("(") + QString::number(numBits) + QString(")"));
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
    drawBitBlock(painter, 0, numBits - numSetBits - numOffsetBits, 0, tagColor, "Tag", width());
    drawBitBlock(painter, 0 + W * (numBits - numSetBits - numOffsetBits), numSetBits, 1, setColor, "Set", width());
    drawBitBlock(painter, 0 + W * (numBits - numOffsetBits), numOffsetBits, 2, offsetColor, "Offset", width());
    drawPointerSizeLabel(painter, numBits);
    painter.end();
}

QSize AddressView::sizeHint() const {
    return QSize(W*numBits, 3*H+30);
}

void AddressView::setNumOffsetBits(int n) {
    numOffsetBits = n;
    update();
}

void AddressView::setNumSetBits(int n) {
    numSetBits = n;
    update();
}

void AddressView::setNumBits(int n) {
    numBits = n;
    update();
}


