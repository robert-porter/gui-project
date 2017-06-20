#include "simulationcontrolsview.h"
#include <QHBoxLayout>
#include <QPushButton>

SimulationControlsView::SimulationControlsView(QWidget *parent) : QWidget(parent)
{
    QLayout *layout = new QVBoxLayout();
    setLayout(layout);
    startButton = new QPushButton("Start", this);

    layout->addWidget(startButton);
    layout->addWidget(new QPushButton("Go", this));
    layout->addWidget(new QPushButton("Step", this));
    layout->addWidget(new QPushButton("Break", this));
}
