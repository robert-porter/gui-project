#include "resultsview.h"

#include <QLabel>
#include <QPushButton>
#include <QFormLayout>

ResultsView::ResultsView(QWidget *parent) : QWidget(parent)
{
    QFormLayout *layout = new QFormLayout(this);
    numAccessesLabel = new QLabel(this);
    hitRatioLabel = new QLabel(this);
    cumpulsoryMissRatioLabel = new QLabel(this);
    missRatioLabel = new QLabel(this);
    layout->addRow("Number of accesses", numAccessesLabel);
    layout->addRow("Hit ratio", hitRatioLabel);
    layout->addRow("Compulsory miss ratio", cumpulsoryMissRatioLabel);
    layout->addRow("Miss ratio", missRatioLabel);
}

void ResultsView::setResults(CacheSimulationResults results) {
    numAccessesLabel->setText(QString::number(results.numAccesses));
    hitRatioLabel->setText(QString::number(results.hitRatio));
    cumpulsoryMissRatioLabel->setText(QString::number(results.compulsoryMissRatio));
    missRatioLabel->setText(QString::number(results.missRatio));
}
