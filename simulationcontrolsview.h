#ifndef SIMULATIONCONTROLSVIEW_H
#define SIMULATIONCONTROLSVIEW_H

#include <QWidget>
#include <QPushButton>

class SimulationControlsView : public QWidget
{
public:
    SimulationControlsView(QWidget *parent);

    QPushButton *startButton;
};

#endif // SIMULATIONCONTROLSVIEW_H
