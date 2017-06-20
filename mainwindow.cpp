#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QDockWidget>
#include <QMenuBar>
#include <QFileDialog>
#include "mainwindow.h"
#include <stdlib.h>
#include "bitslider.h"
#include "traceview.h"
#include "parametersview.h"
#include "resultsview.h"
#include "addressview.h"


void MainWindow::createFileMenu() {
    QMenu *fileMenu = menuBar()->addMenu("File");

    QAction *openAction = new QAction("Open", this);
    connect(openAction, SIGNAL(triggered()), this, SLOT(fileOpenTriggered()));
    fileMenu->addAction(openAction);

    QAction *saveAsAction = new QAction("Save as", this);
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(fileSaveAsTriggered()));
    fileMenu->addAction(saveAsAction);

    QAction *quitAction = new QAction("Quit", this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    fileMenu->addAction(quitAction);

}

void MainWindow::fileOpenTriggered() {
    QString filename = QFileDialog::getOpenFileName(this);
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    std::vector<QString> addresses;
    while (!file.atEnd()) {
        QString line = file.readLine();
        addresses.push_back(line.trimmed());
    }

    traceView->setTrace(addresses);
}

void MainWindow::fileSaveAsTriggered() {
    QString filename = QFileDialog::getSaveFileName(this);
}


void MainWindow::createDockViewsAndViewMenu() {
    QMenu *viewMenu = menuBar()->addMenu("View");

    QDockWidget *lrDockWidget = new QDockWidget("Cache parameters", this);
    lrDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                   Qt::RightDockWidgetArea);
    lrDockWidget->setWidget(parametersView);
    addDockWidget(Qt::LeftDockWidgetArea, lrDockWidget);

    viewMenu->addAction(lrDockWidget->toggleViewAction());

    QDockWidget *bDockWidget = new QDockWidget("Results", this);
    bDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    bDockWidget->setWidget(resultsView);
    addDockWidget(Qt::BottomDockWidgetArea, bDockWidget);

    viewMenu->addAction(bDockWidget->toggleViewAction());
}

void MainWindow::createHelpMenu() {
    QMenu *helpMenu = menuBar()->addMenu("Help");
    QAction *showHelpAction = new QAction("Help", this);
    connect(showHelpAction, SIGNAL(triggered()), this, SLOT(showHelp()));
    helpMenu->addAction(showHelpAction);

}

void MainWindow::showHelp() {
    QLabel *label = new QLabel("This is no help");
    label->show();
}

MainWindow::MainWindow() : QMainWindow(0)
{
    traceView = new TraceView(this);
    parametersView = new ParametersView(this);
    resultsView = new ResultsView(this);

    connect(parametersView, SIGNAL(startSimulation(CacheSimulationParameters)), &cacheSimulator, SLOT(runSimulation(CacheSimulationParameters)));
    connect(&cacheSimulator, SIGNAL(resultsChanged(CacheSimulationResults)), resultsView, SLOT(setResults(CacheSimulationResults)));

    setCentralWidget(traceView);

    // order matters here
    createFileMenu();
    createDockViewsAndViewMenu();
    createHelpMenu();

    show();
}
