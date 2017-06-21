#include "simulationcontrolsview.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>

SimulationControlsView::SimulationControlsView(QWidget *parent) : QWidget(parent)
{
    QFormLayout *layout = new QFormLayout();
    setLayout(layout);
    startButton = new QPushButton("Start", this);

    layout->addRow(startButton, (QWidget *) NULL);
    layout->addRow(new QPushButton("Go", this), (QWidget *) NULL);
    layout->addRow(new QPushButton("Step", this), new QLineEdit());
    layout->addRow(new QPushButton("Break", this), new QLineEdit());
}
