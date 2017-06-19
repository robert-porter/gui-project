#ifndef CACHEVIEW_H
#define CACHEVIEW_H

#include <QWidget>
#include "bitslider.h"
#include <QSpinBox>
#include <QComboBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QFormLayout>
#include <QPainter>

class CacheView : public QWidget
{
    Q_OBJECT
public:
    CacheView(QWidget *parent);
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
};

#endif // CACHEVIEW_H
