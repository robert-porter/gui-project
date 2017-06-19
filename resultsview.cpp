#include "resultsview.h"

#include <QLabel>
#include <QPushButton>

ResultsView::ResultsView(QWidget *parent) : QGroupBox("Results", parent)
{
    QFormLayout *layout = new QFormLayout(this);

   // QWidget *goButton = new QPushButton("Go");
    layout->addRow("Number of accesses", new QLabel("100"));
    layout->addRow("Hit ratio", new QLabel("45"));
    layout->addRow("Compulsory miss ratio", new QLabel("66"));
    layout->addRow("Miss ratio", new QLabel("33"));
}
