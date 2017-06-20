#ifndef TRACEVIEW_H
#define TRACEVIEW_H


#include <QWidget>
#include <QPlainTextEdit>
#include <stdlib.h>
#include <vector>

class TraceView : public QPlainTextEdit {
    Q_OBJECT
public:
    TraceView(QWidget *parent);
    void setTrace(std::vector<QString> addresses);
    void setLeadingText(QString t, int position);
    void setStart(int position);
    void addBreakpoint(int position);
    void removeBreakpoint(int position);
    bool hasBreakpoint(int position);
    void toggleBreakpoint(int position);
    void mousePressEvent(QMouseEvent *e);
    QSize minimumSizeHint() const { return sizeHint(); }
protected:
    int start;

    std::vector<int> breakpoints;
};


#endif // TRACEVIEW_H
