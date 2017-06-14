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

QGroupBox *createCacheType() {
    QGroupBox *groupBox = new QGroupBox();

    QRadioButton *radio1 = new QRadioButton("Instruction cache");
    QRadioButton *radio2 = new QRadioButton("Data cache");

    radio1->setChecked(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(radio1);
    layout->addWidget(radio2);
    layout->addStretch(1);
    groupBox->setLayout(layout);

    return groupBox;
}

QComboBox *createReplacementPolicy() {
    QComboBox *replacementPolicyComboBox = new QComboBox(0);
    replacementPolicyComboBox->insertItem(0, "LRU");
    replacementPolicyComboBox->insertItem(1, "LFU");
    replacementPolicyComboBox->insertItem(2, "Random");
    return replacementPolicyComboBox;
}

QGroupBox *createCacheTypeParemeters() {
    QFormLayout *layout = new QFormLayout;
    QGroupBox *groupBox = new QGroupBox();

    layout->addRow("Replacement policy", createReplacementPolicy());
    layout->addRow("Cache type", createCacheType());
    groupBox->setLayout(layout);
    return groupBox;
}

QGroupBox *createCacheSizeParemeters() {
    QGroupBox *groupBox = new QGroupBox();

    AddressView *addressView = new AddressView(0);
    BitSlider *lineSize = new BitSlider(0, true);
    BitSlider *setsSlider = new BitSlider(0, false);
    QSpinBox *waysSpinBox = new QSpinBox(0);

    QFormLayout *layout = new QFormLayout;
    layout->addRow(addressView);
    layout->addRow("Line size", lineSize);
    layout->addRow("Number of sets", setsSlider);
    layout->addRow("Number of ways", waysSpinBox);
    groupBox->setLayout(layout);

    QObject::connect(lineSize, SIGNAL(pointerSizeChanged(int)), addressView, SLOT(setNumOffsetBits(int)));
    QObject::connect(setsSlider, SIGNAL(pointerSizeChanged(int)), addressView, SLOT(setNumSetBits(int)));

    setsSlider->setPointerRange(0, 16);
    lineSize->setPointerRange(1, 14);
    waysSpinBox->setRange(1, 16);
    // set the values after connecting controls to labels
    setsSlider->setPointerValue(0);
    waysSpinBox->setValue(1);

    return groupBox;
}

CacheView::CacheView(QWidget *parent) : QWidget(parent)
{
    QLayout *layout = new QHBoxLayout();
    setLayout(layout);

    layout->addWidget(createCacheTypeParemeters());
    layout->addWidget(createCacheSizeParemeters());

}
