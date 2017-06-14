#include "traceview.h"


TraceView::TraceView(QWidget *parent) : QPlainTextEdit(parent) {

    for(int i = 0; i < 100; i++) {
        this->appendPlainText(QString("   ") + QString("0xFFFFFFFF"));
    }

    start = 0;
    setStart(start);
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

void TraceView::setStart(int position) {

    setLeadingText("   ", start);
    start = position;
    setLeadingText("S: ", start);
}


void TraceView::mousePressEvent(QMouseEvent *e) {
    QWidget::mousePressEvent(e);
    setStart(cursorForPosition(e->pos()).blockNumber());
}

