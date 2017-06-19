#ifndef ADDRESSVIEW_H
#define ADDRESSVIEW_H

#include <QWidget>
#include <QPainter>


class AddressView : public QWidget {
    Q_OBJECT
public:
    AddressView(QWidget *parent);
protected:
    void drawBitBlock(QPainter &painter, int xStart, int numBits, int blockIndex, QColor color, QString text, int widgetWidth);
    void drawPointerSizeLabel(QPainter &painter, int numBits);
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;

public slots:
    void setNumBits(int n);
    void setNumOffsetBits(int n);
    void setNumSetBits(int n);

protected:
    int numOffsetBits;
    int numSetBits;
    int numBits;
};


#endif // ADDRESSVIEW_H
