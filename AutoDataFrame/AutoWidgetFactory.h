#pragma once
#include <QString>
#include <QMap>
#include "AutoBaseWidget.h"

class AutoWidgetFactory
{
public:
    virtual AutoBaseWidget* createWidget(const QString& typeName, QWidget* parent) = 0;
    virtual ~AutoWidgetFactory() {}
};
