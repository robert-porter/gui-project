#include <QApplication>
#include <QWidget>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QHBoxLayout>
#include <QScrollArea>
#include <stdlib.h>
#include "bitslider.h"
#include "traceview.h"
#include "cacheview.h"
#include "resultsview.h"
#include "addressview.h"

int main(int argc, char **argv) {


    QApplication app(argc, argv);
    QWidget window(0);

    QGridLayout *layout = new QGridLayout();
    window.setLayout(layout);

    layout->addWidget(new TraceView(&window), 0, 0);
    layout->addWidget(new CacheView(&window), 0, 1);
    layout->addWidget(new ResultsView(&window), 1, 0, 1, 2);

    window.show();

    app.exec();
}
