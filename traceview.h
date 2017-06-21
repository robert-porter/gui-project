#ifndef TRACEVIEW_H
#define TRACEVIEW_H


#include <QWidget>
#include <QPlainTextEdit>
#include <stdlib.h>
#include <set>

class TraceView : public QPlainTextEdit {
    Q_OBJECT
public:
    TraceView(QWidget *parent);
    void setTrace(std::vector<QString> addresses);
    void setLeadingText(QString t, int position);
    void toggleBreakpoint(int position);
    void mousePressEvent(QMouseEvent *e);
    QSize minimumSizeHint() const { return sizeHint(); }
protected:

    std::set<int> breakpoints;
};


#endif // TRACEVIEW_H
