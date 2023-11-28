#pragma once
#include <QString>
#include <QMap>
#include <QDomElement>
#include "AutoBaseWidget.h"
#include "AMLabelLabel.h"
#include "AMLabelLineLabel.h"

class AUTODATAFRAME_EXPORT AutoWidgetFactory
{
public:
    virtual AutoBaseWidget* createWidget(const QString& typeName, QDomElement ele, QWidget* parent);
    virtual ~AutoWidgetFactory() {}
};
