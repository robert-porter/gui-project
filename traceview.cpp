#include <QTextBlock>
#include "traceview.h"


TraceView::TraceView(QWidget *parent) : QPlainTextEdit(parent) {
    start = 0;
    setStart(start);
}

void TraceView::setTrace(std::vector<QString> addresses) {
    this->clear();
    for(size_t i = 0; i < addresses.size(); i++) {
        appendPlainText(QString("   ") + addresses[i]);
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

