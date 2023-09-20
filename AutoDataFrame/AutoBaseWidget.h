#pragma once
#include <QtWidgets/QWidget>

class AutoBaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AutoBaseWidget(QWidget* parent = nullptr) : QWidget(parent) {}
    virtual ~AutoBaseWidget() {}
};
