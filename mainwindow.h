#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "traceview.h"
#include "parametersview.h"
#include "resultsview.h"
#include "graphicsview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
protected:
    void createFileMenu();
    void createHelpMenu();
    void createDockViewsAndViewMenu();
    void createConvertMenu();
public slots:
    void fileOpenTriggered();
    void fileSaveAsTriggered();
    void showHelp();
    void convertHexFile();
private:
    TraceView *traceView;
    ResultsView *resultsView;
    ParametersView *parametersView;
    GraphicsView *graphicsView;

    CacheSimulator cacheSimulator;

};

#endif // MAINWINDOW_H
