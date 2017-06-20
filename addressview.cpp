#include "addressview.h"

const int W = 8;
const int H = 20;

int textHeight = 20;
int bitBlockHeight = 20;
int pointerLineLabelHeight = 10;
int labelLineHeight = 20;

AddressView::AddressView(QWidget *parent) :QWidget(parent) {
    numOffsetBits = 0;
    numSetBits = 0;
    numBits = 32;
    setMinimumSize(sizeHint());
}

void AddressView::drawBitBlock(QPainter &painter, int xStart, int y, int numBits, int blockIndex, QColor color, QString text, int widgetWidth) {

    int textTop = y + bitBlockHeight + labelLineHeight;
    int textLeft = widgetWidth * blockIndex / 3;
    int labelLineStartX = widgetWidth * (1 + 2 * blockIndex) / 6;
    int heightOffset = 2 + blockIndex * 4;
    int labelLineDestX = xStart + (W * numBits) / 2;

    painter.setBrush(color);
    for(int i = 0; i < numBits; i++) {
        painter.drawRoundedRect(xStart + W*i, y, W, H, 3.0f, 3.0f);
    }

    painter.drawText(textLeft, textTop, widgetWidth / 3, textHeight, Qt::AlignCenter, text + QString("(") + QString::number(numBits) + QString(")"));
    if(numBits <= 0) // don't draw label line if no bits
        return;
    painter.drawLine(QPointF(labelLineStartX, textTop), QPointF(labelLineStartX, textTop - heightOffset));
    painter.drawLine(QPointF(labelLineStartX, textTop - heightOffset), QPointF(labelLineDestX, textTop - heightOffset));
    painter.drawLine(QPointF(labelLineDestX, textTop - heightOffset), QPointF(labelLineDestX, y + bitBlockHeight + 4));
    painter.drawLine(QPointF(labelLineDestX, y + bitBlockHeight + 4), QPointF(labelLineDestX - (numBits - 1) * W / 2.0, y + bitBlockHeight + 4));
    painter.drawLine(QPointF(labelLineDestX - (numBits - 1) * W / 2.0, y + bitBlockHeight + 4), QPointF(labelLineDestX - (numBits - 1) * W / 2.0, y + bitBlockHeight + 2));
    painter.drawLine(QPointF(labelLineDestX, y + bitBlockHeight + 4), QPointF(labelLineDestX + (numBits - 1) * W / 2.0, y + bitBlockHeight + 4));
    painter.drawLine(QPointF(labelLineDestX + (numBits - 1) * W / 2.0, y + bitBlockHeight + 4), QPointF(labelLineDestX + (numBits - 1) * W / 2.0, y + bitBlockHeight + 2));

}

void AddressView::drawPointerSizeLabel(QPainter &painter, int y, int numBits) {
    int w = width();
    painter.drawLine(QPoint(w / 2, y), QPoint(w / 2, y + 5));
    painter.drawLine(QPoint(w / 2, y + 5), QPoint(w / 2 + (numBits - 1) * W / 2.0, y + 5));
    painter.drawLine(QPoint(w / 2 + (numBits - 1) * W / 2.0, y + 5), QPoint(w / 2 + (numBits - 1) * W / 2.0, y + 7));
    painter.drawLine(QPoint(w / 2, y + 5), QPoint(w / 2 -  (numBits - 1) * W / 2.0, y + 5));
    painter.drawLine(QPoint(w / 2 -  (numBits - 1) * W / 2.0, y + 5), QPoint(w / 2 -  (numBits - 1) * W / 2.0, y + 7));
}

void AddressView::paintEvent(QPaintEvent *)
{
    const QColor tagColor = QColor(255, 0, 0);
    const QColor setColor = QColor(0, 255, 0);
    const QColor offsetColor = QColor(0, 0, 255);

    QPainter painter;
    painter.begin(this);
    QFont font=painter.font() ;
    font.setStyleStrategy(QFont::NoAntialias);
    painter.setFont(font);

    painter.drawText(0, 0, width(), H, Qt::AlignCenter, "Pointer size" + QString("(") + QString::number(numBits) + QString(")"));
    drawPointerSizeLabel(painter, textHeight, numBits);
    int offset = (width() - numBits * W) / 2;

    drawBitBlock(painter, offset, textHeight + pointerLineLabelHeight, numBits - numSetBits - numOffsetBits, 0, tagColor, "Tag", width());
    drawBitBlock(painter, offset + W * (numBits - numSetBits - numOffsetBits), textHeight + pointerLineLabelHeight, numSetBits, 1, setColor, "Set", width());
    drawBitBlock(painter, offset + W * (numBits - numOffsetBits), textHeight + pointerLineLabelHeight, numOffsetBits, 2, offsetColor, "Offset", width());

    painter.end();
}

QSize AddressView::sizeHint() const {
    return QSize(W*numBits, textHeight + bitBlockHeight + pointerLineLabelHeight + labelLineHeight + textHeight);
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


