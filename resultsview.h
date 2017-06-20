#ifndef RESULTSVIEW_H
#define RESULTSVIEW_H

#include <QWidget>
#include <QLabel>
#include "cachesimulator.h"

class ResultsView : public QWidget
{
    Q_OBJECT
public:
    ResultsView(QWidget *parent);
public slots:
    void setResults(CacheSimulationResults results);
protected:
    QLabel *numAccessesLabel;
    QLabel *hitRatioLabel;
    QLabel *cumpulsoryMissRatioLabel;
    QLabel *missRatioLabel;
};

#endif // RESULTSVIEW_H
