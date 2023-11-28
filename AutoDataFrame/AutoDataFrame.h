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
    QMap<QString, QVariant> getAMMap();

    void isAutoSaved(bool b) { b_isAutoSaved = b; }

    void saveXML();


private:
    void recurParseNode(QDomElement element, QWidget* parentWidget, QGridLayout* gridLayout, QString& msg);
    QMap<QString, QVariant> p_widgetMap;
    QMap<QString, QVariant> p_AMMap;

    AutoWidgetFactory* m_widgetFactory = nullptr;

    bool b_isAutoSaved = false;

    void parseTabWidgetNode(QDomElement element, QTabWidget* tabWidget, QGridLayout* gridLayout, QString& msg);
};
