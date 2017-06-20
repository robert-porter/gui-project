#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "traceview.h"
#include "parametersview.h"
#include "resultsview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
protected:
    void createFileMenu();
    void createHelpMenu();
    void createDockViewsAndViewMenu();
public slots:
    void fileOpenTriggered();
    void fileSaveAsTriggered();
    void showHelp();
private:
    TraceView *traceView;
    ResultsView *resultsView;
    ParametersView *parametersView;
    CacheSimulator cacheSimulator;
};

#endif // MAINWINDOW_H
