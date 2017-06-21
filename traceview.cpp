#include <QTextBlock>
#include "traceview.h"


TraceView::TraceView(QWidget *parent) : QPlainTextEdit(parent) {
}

void TraceView::setTrace(std::vector<QString> addresses) {
    this->clear();
    for(size_t i = 0; i < addresses.size(); i++) {
        appendPlainText(QString("   ") + addresses[i]);
    }
}

void TraceView::setLeadingText(QString t, int position) {
    QTextCursor cursor(document()->findBlockByNumber(position));

    cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
    cursor.movePosition(QTextCursor::Right, QTextCursor::MoveAnchor, 3);
    cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::KeepAnchor);

    this->setTextCursor(cursor);
    cursor.beginEditBlock();
    cursor.removeSelectedText();
    cursor.insertText(t);
    cursor.endEditBlock();
}

void TraceView::toggleBreakpoint(int position) {
    if(breakpoints.find(position) != breakpoints.end()) {
        breakpoints.erase(breakpoints.find(position));
        setLeadingText("   ", position);
    }
    else {
        breakpoints.insert(position);
        setLeadingText("B: ", position);
    }
}


void TraceView::mousePressEvent(QMouseEvent *e) {
    QWidget::mousePressEvent(e);
    toggleBreakpoint(cursorForPosition(e->pos()).blockNumber());
}

