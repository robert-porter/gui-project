#include "parametersview.h"
#include "bitslider.h"
#include <QRadioButton>
#include <QFormLayout>
#include "simulationcontrolsview.h"
#include "addressview.h"

void ParametersView::createCacheType() {
    cacheTypeGroupBox = new QGroupBox(this);

    QRadioButton *radio1 = new QRadioButton("Instruction cache");
    QRadioButton *radio2 = new QRadioButton("Data cache");

    radio1->setChecked(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(radio1);
    layout->addWidget(radio2);
    layout->addStretch(1);
    cacheTypeGroupBox->setLayout(layout);
}

CACHE_TYPE getSelectedCacheType(QGroupBox *groupBox) {
    QList<QRadioButton *> radios = groupBox->findChildren<QRadioButton *>();
    for(int i = 0; i < radios.size(); ++i)
    {
        if(radios[i]->isChecked())
            return CACHE_TYPE(i);
    }
    return CACHE_TYPE(0);
}

void ParametersView::createReplacementPolicy() {
    replacementPolicyComboBox = new QComboBox(this);
    replacementPolicyComboBox->insertItem(0, "LRU", QVariant(int(LRU)));
    replacementPolicyComboBox->insertItem(1, "LFU", QVariant(int(LRU)));
    replacementPolicyComboBox->insertItem(2, "Random", QVariant(int(LRU)));
}

QGroupBox *ParametersView::createCacheTypeParemeters() {
    createCacheType();
    createReplacementPolicy();

    QFormLayout *layout = new QFormLayout;
    QGroupBox *groupBox = new QGroupBox(this);

    layout->addRow("Replacement policy", replacementPolicyComboBox);
    layout->addRow("Cache type", cacheTypeGroupBox);
    groupBox->setLayout(layout);
    return groupBox;
}

QGroupBox *ParametersView::createCacheSizeParemeters() {
    QGroupBox *groupBox = new QGroupBox(this);

    AddressView *addressView = new AddressView(this);
    mainMemorySizeSlider = new BitSlider(this, true);
    lineSizeSlider = new BitSlider(this, true);
    setsSlider = new BitSlider(this, false);
    waysSpinBox = new QSpinBox(this);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(addressView);
    layout->addRow("Main memory size", mainMemorySizeSlider);
    layout->addRow("Line size", lineSizeSlider);
    layout->addRow("Number of sets", setsSlider);
    layout->addRow("Number of ways", waysSpinBox);
    groupBox->setLayout(layout);

    QObject::connect(mainMemorySizeSlider, SIGNAL(pointerSizeChanged(int)), addressView, SLOT(setNumBits(int)));
    QObject::connect(lineSizeSlider, SIGNAL(pointerSizeChanged(int)), addressView, SLOT(setNumOffsetBits(int)));
    QObject::connect(setsSlider, SIGNAL(pointerSizeChanged(int)), addressView, SLOT(setNumSetBits(int)));

    QObject::connect(mainMemorySizeSlider, SIGNAL(pointerSizeChanged(int)), this, SLOT(mainMemorySizeChanged(int)));
    QObject::connect(lineSizeSlider, SIGNAL(pointerSizeChanged(int)), this, SLOT(lineSizeChanged(int)));
    QObject::connect(setsSlider, SIGNAL(pointerSizeChanged(int)), this, SLOT(numSetsChanged(int)));


    setsSlider->setPointerRange(0, 16);
    lineSizeSlider->setPointerRange(1, 14);
    waysSpinBox->setRange(1, 16);

    mainMemorySizeSlider->setPointerRange(8, 28);
    // set the values after connecting controls to labels
    mainMemorySizeSlider->setPointerSize(8);
    setsSlider->setPointerSize(0);
    waysSpinBox->setValue(1);

    return groupBox;
}

void ParametersView::start() {
    CacheSimulationParameters parameters;
    parameters.pointerSize = mainMemorySizeSlider->getPointerSize();
    parameters.lineSize = static_cast<unsigned long long>(1) << lineSizeSlider->getPointerSize();
    parameters.numSets = setsSlider->getPointerSize();
    parameters.numWays = waysSpinBox->value();
    parameters.type = getSelectedCacheType(cacheTypeGroupBox);
    parameters.replacementPolicy = REPLACEMENT_POLICY(replacementPolicyComboBox->itemData(replacementPolicyComboBox->currentIndex()).toInt());
   // unsigned long *trace;
   // int traceSize;
    emit startSimulation(parameters);
}

void ParametersView::mainMemorySizeChanged(int n) {
    // clamp slider sizes to be no bigger than memory size allows
    setsSlider->setPointerRange(0, std::min(n-1, 16)); // subtract 1 since min pointerSize for lines = 1
    lineSizeSlider->setPointerRange(1, std::min(n, 14));

    if(lineSizeSlider->getPointerSize() + setsSlider->getPointerSize() > n) {
        int newSetsSize = n - lineSizeSlider->getPointerSize();

        if(newSetsSize >= 0) { // take from sets first
            setsSlider->setPointerSize(newSetsSize);
        }
        else { // then take from line bits
            setsSlider->setPointerSize(0);
            lineSizeSlider->setPointerSize(n);
        }
    }
}
void ParametersView::lineSizeChanged(int n) {
   // take from sets with overflow
   if(n + setsSlider->getPointerSize() > mainMemorySizeSlider->getPointerSize()) {
        int newSetsSize = mainMemorySizeSlider->getPointerSize() - n;
        setsSlider->setPointerSize(newSetsSize);
   }
}

void ParametersView::numSetsChanged(int n) {
    // take from line size with overflow
    if(n + lineSizeSlider->getPointerSize() > mainMemorySizeSlider->getPointerSize()) {
         int newLineSizeSize = mainMemorySizeSlider->getPointerSize() - n;
         lineSizeSlider->setPointerSize(newLineSizeSize);
    }
}

ParametersView::ParametersView(QWidget *parent) : QWidget(parent)
{
    QWidget *w = new QWidget(this);
    QLayout *layout = new QVBoxLayout();
    w->setLayout(layout);

    layout->addWidget(createCacheTypeParemeters());
    layout->addWidget(createCacheSizeParemeters());

    QLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(w);
    simulationControlsView = new SimulationControlsView(w);
    mainLayout->addWidget(simulationControlsView);
    setLayout(mainLayout);

    connect(simulationControlsView->startButton, SIGNAL(pressed()), this, SLOT(start()));
}
