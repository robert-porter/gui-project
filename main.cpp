#include <QApplication>
#include <QWidget>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QMainWindow>
#include <QDockWidget>
#include <stdlib.h>
#include "bitslider.h"
#include "traceview.h"
#include "cacheview.h"
#include "resultsview.h"
#include "addressview.h"


void dockLR(QMainWindow *w, QWidget *c) {
    QDockWidget *dockWidget = new QDockWidget("Dock Widget", w);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                   Qt::RightDockWidgetArea);
    dockWidget->setWidget(c);
    w->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);
}

void dockB(QMainWindow *w, QWidget *c) {
    QDockWidget *dockWidget = new QDockWidget("Dock Widget", w);
    dockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    dockWidget->setWidget(c);
    w->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
}

int main(int argc, char **argv) {


    QApplication app(argc, argv);
    QMainWindow window(0);

    //QGridLayout *layout = new QGridLayout();
   // window.setLayout(layout);

    window.setCentralWidget(new TraceView(&window));
 //   dock(&window, new TraceView(&window));
    dockLR(&window, new CacheView(&window));
    dockB(&window, new ResultsView(&window));
  //  layout->addWidget(new TraceView(&window), 0, 0);
  //  layout->addWidget(new CacheView(&window), 0, 1);
  //  layout->addWidget(new ResultsView(&window), 1, 0, 1, 2);

    window.show();

    app.exec();
}
