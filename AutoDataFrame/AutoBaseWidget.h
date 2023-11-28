#pragma once
#include <QtWidgets/QWidget>
#include "AUtils.h"
#include "autodataframe_global.h"
class AUTODATAFRAME_EXPORT AutoBaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AutoBaseWidget(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~AutoBaseWidget() {};
    
public:
    CLASS_VAR_DECLEAR(int, id);
    CLASS_VAR_DECLEAR(QString, name);
    CLASS_VAR_DECLEAR(QString, value);
    CLASS_VAR_DECLEAR(QString, unit);
};
