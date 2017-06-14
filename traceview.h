#ifndef TRACEVIEW_H
#define TRACEVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QTextBlock>
#include <QSpinBox>
#include <QSlider>
#include <stdlib.h>
#include <QWidget>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QHBoxLayout>
#include <QScrollArea>
#include <stdlib.h>

class TraceView : public QPlainTextEdit {
    Q_OBJECT
public:
    TraceView(QWidget *parent);
    void setLeadingText(QString t, int position);
    void setStart(int position);
    void mousePressEvent(QMouseEvent *e);
    QSize minimumSizeHint() const { return sizeHint(); }
protected:
    int start;
};


#endif // TRACEVIEW_H
