#ifndef CACHEVIEW_H
#define CACHEVIEW_H

#include <QWidget>
#include <QSpinBox>
#include <QComboBox>
#include <QGroupBox>
#include "bitslider.h"
#include "cachesimulator.h"
#include "simulationcontrolsview.h"

class ParametersView : public QWidget
{
    Q_OBJECT
public:
    ParametersView(QWidget *parent);
    void emitChanged();


public slots:
    void mainMemorySizeChanged(int n);
    void lineSizeChanged(int n);
    void numSetsChanged(int n);

signals:
    void startSimulation(CacheSimulationParameters parameters);
    void changed(int a, int b, int c, int d);
protected slots:
    void start();
protected:
    void createCacheType();
    void createReplacementPolicy();
    QGroupBox *createCacheTypeParemeters();
    QGroupBox *createCacheSizeParemeters();

protected:
    QGroupBox *cacheTypeGroupBox;
    QComboBox *replacementPolicyComboBox;
    BitSlider *mainMemorySizeSlider;
    BitSlider *lineSizeSlider;
    BitSlider *setsSlider;
    QSpinBox *waysSpinBox;
    SimulationControlsView *simulationControlsView;
};

#endif // CACHEVIEW_H
