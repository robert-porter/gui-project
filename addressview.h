#ifndef ADDRESSVIEW_H
#define ADDRESSVIEW_H

#include <QWidget>
#include <QPainter>


class AddressView : public QWidget {
    Q_OBJECT
public:
    AddressView(QWidget *parent);
protected:
    void paintEvent(QPaintEvent *);
    QSize sizeHint() const;

public slots:
    void setNumOffsetBits(int n);
    void setNumSetBits(int n);

protected:
    int numOffsetBits;
    int numTagBits;
    int numSetBits;
    int numBits;
};


#endif // ADDRESSVIEW_H
