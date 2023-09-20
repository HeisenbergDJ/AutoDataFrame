#pragma once
#include <QtWidgets/QWidget>
#include <QFile>
#include <QDomDocument>
#include <QGridLayout>
#include <QGroupBox>
#include <QTreeView>
#include <QSplitter>
#include "AutoBaseWidget.h"
#include "AutoWidgetFactory.h"
#include "autodataframe_global.h"

class AUTODATAFRAME_EXPORT AutoDataFrame : QWidget
{
public:
    AutoDataFrame(QWidget* parent = nullptr);
    ~AutoDataFrame();
    void setFactory(AutoWidgetFactory* widgetFactory) { m_widgetFactory = widgetFactory; }
    QWidget* getWidgetfromAutoData(QString autoDataFilePath, QString& msg=QString(""));
    QMap<QString, QVariant> getAutoWidgetMap();

private:
    void parseSubWidgetNode(QDomElement element, QWidget* parentWidget, QGridLayout* gridLayout, QString& msg);
    QMap<QString, QVariant> p_widgetMap;
    AutoWidgetFactory* m_widgetFactory = nullptr;

};
