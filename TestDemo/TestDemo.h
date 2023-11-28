#pragma once

#include <QtWidgets/QWidget>
#include "ui_TestDemo.h"

class TestDemo : public QWidget
{
    Q_OBJECT

public:
    TestDemo(QWidget *parent = nullptr);
    ~TestDemo();

private:
    Ui::TestDemoClass ui;
};
