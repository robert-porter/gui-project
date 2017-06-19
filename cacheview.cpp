#include "cacheview.h"
#include "bitslider.h"
#include <QSpinBox>
#include <QComboBox>
#include <QButtonGroup>
#include <QGroupBox>
#include <QRadioButton>
#include <QFormLayout>
#include <QPainter>
#include "addressview.h"

void CacheView::createCacheType() {
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

void CacheView::createReplacementPolicy() {
    replacementPolicyComboBox = new QComboBox(this);
    replacementPolicyComboBox->insertItem(0, "LRU");
    replacementPolicyComboBox->insertItem(1, "LFU");
    replacementPolicyComboBox->insertItem(2, "Random");
}

QGroupBox *CacheView::createCacheTypeParemeters() {
    createCacheType();
    createReplacementPolicy();

    QFormLayout *layout = new QFormLayout;
    QGroupBox *groupBox = new QGroupBox(this);

    layout->addRow("Replacement policy", replacementPolicyComboBox);
    layout->addRow("Cache type", cacheTypeGroupBox);
    groupBox->setLayout(layout);
    return groupBox;
}

QGroupBox *CacheView::createCacheSizeParemeters() {
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

    mainMemorySizeSlider->setPointerRange(8, 28);
    mainMemorySizeSlider->setPointerValue(8);
    setsSlider->setPointerRange(0, 16);
    lineSizeSlider->setPointerRange(1, 14);
    waysSpinBox->setRange(1, 16);
    // set the values after connecting controls to labels
    setsSlider->setPointerValue(0);
    waysSpinBox->setValue(1);

    return groupBox;
}

CacheView::CacheView(QWidget *parent) : QWidget(parent)
{
    QLayout *layout = new QVBoxLayout();
    setLayout(layout);

    layout->addWidget(createCacheTypeParemeters());
    layout->addWidget(createCacheSizeParemeters());

}
