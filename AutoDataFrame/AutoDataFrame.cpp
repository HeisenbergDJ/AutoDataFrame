#include "AutoDataFrame.h"

AutoDataFrame::AutoDataFrame(QWidget* parent)
    : QWidget(parent)
{
}

AutoDataFrame::~AutoDataFrame()
{}

QWidget* AutoDataFrame::getWidgetfromAutoData(QString autoDataFilePath, QString& msg)
{
    if (!m_widgetFactory) {
        msg.append(QStringLiteral("未设置自定义的factory类\n"));
        return nullptr;
    }

    QFile file(autoDataFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        msg.append(QStringLiteral("文件：%1\n无法打开").arg(autoDataFilePath));
        return nullptr;
    }
    QDomDocument m_xmlDoc;
    QString errorMsg;
    if (!m_xmlDoc.setContent(&file, &errorMsg)) {
        msg.append(QStringLiteral("文件：%1\n的内容不符合标准xml文件\n错误原因可能是：%2")
            .arg(autoDataFilePath)
            .arg(errorMsg));
        file.close();
        return nullptr;
    }
    file.close();

    QWidget* mainWidget = new QWidget(this);
    QGridLayout* mainGridLayout = new QGridLayout();
    mainWidget->setLayout(mainGridLayout);
    QDomElement root = m_xmlDoc.documentElement();
    QDomElement widgetElement = root.firstChildElement();
    parseSubWidgetNode(widgetElement, this, mainGridLayout, msg);
    return mainWidget;
}

QMap<QString, QVariant> AutoDataFrame::getAutoWidgetMap()
{
    return p_widgetMap;
}

void AutoDataFrame::parseSubWidgetNode(QDomElement element, QWidget* parentWidget, QGridLayout* gridLayout, QString& msg)
{
    while (!element.isNull())
    {
        if (element.tagName() == "Splitter")
        {
            QSplitter* splitter = new QSplitter(parentWidget);
            if (element.attribute("splitterType") == "Horizontal") {
                splitter->setOrientation(Qt::Horizontal);
            }
            else {
                splitter->setOrientation(Qt::Vertical);
            }
            QString objName = element.attribute("name");
            gridLayout->addWidget(splitter);
            int childNodeNum = element.childNodes().size();
            parseSubWidgetNode(element.firstChildElement(), splitter, nullptr, msg);
            QStringList stretchFactorStrList = element.attribute("stretchFactor").split(",");
            for (int i = 0; i < stretchFactorStrList.size(); i++) {
                int a = stretchFactorStrList.at(i).toInt();
                splitter->setStretchFactor(i, stretchFactorStrList.at(i).toInt());
            }
        }
        else if (element.tagName() == "Widget")
        {
            QWidget* widget;
            QStringList layoutPosition_ = element.attribute("layoutPosition").split(",");
            QString objName = element.attribute("name");
            widget = new QWidget(parentWidget);
            QGridLayout* layout = new QGridLayout;
            widget->setLayout(layout);
            widget->setObjectName(objName);
            p_widgetMap.insert(objName, QVariant::fromValue(widget));
            QStringList layoutPosition = { "0","0","1","1" };//默认的配置,避免索引越界
            for (int i = 0; i < layoutPosition_.size(); i++) {
                layoutPosition[i] = layoutPosition_.at(i);
            }
            if (gridLayout) {
                gridLayout->addWidget(widget, layoutPosition.at(0).toInt(), layoutPosition.at(1).toInt(), layoutPosition.at(2).toInt(), layoutPosition.at(3).toInt());
            }
            parseSubWidgetNode(element.firstChildElement(), widget, layout, msg);
        }
        else if (element.tagName() == "GroupBox")
        {
            QWidget* widget;
            QStringList layoutPosition_ = element.attribute("layoutPosition").split(",");
            QString objName = element.attribute("name");
            widget = new QGroupBox(element.attribute("displayName"), parentWidget);
            QGridLayout* layout = new QGridLayout;
            widget->setLayout(layout);
            widget->setObjectName(objName);
            p_widgetMap.insert(objName, QVariant::fromValue(widget));
            QStringList layoutPosition = { "0","0","1","1" };//默认的配置,避免索引越界
            for (int i = 0; i < layoutPosition_.size(); i++) {
                layoutPosition[i] = layoutPosition_.at(i);
            }
            if (gridLayout) {
                gridLayout->addWidget(widget, layoutPosition.at(0).toInt(), layoutPosition.at(1).toInt(), layoutPosition.at(2).toInt(), layoutPosition.at(3).toInt());
            }
            parseSubWidgetNode(element.firstChildElement(), widget, layout, msg);
        }
        else if (element.tagName() == "Container") {
            QString type = element.attribute("type");
            QStringList layoutPosition_ = element.attribute("layoutPosition").split(",");
            QString objName = element.attribute("name");
            QGridLayout* layout = new QGridLayout;
            AutoBaseWidget* baseWidget = m_widgetFactory->createWidget(type, parentWidget);
            if (baseWidget) {
                baseWidget->setLayout(layout);
                baseWidget->setObjectName(objName);
                p_widgetMap.insert(objName, QVariant::fromValue(baseWidget));
                QStringList layoutPosition = { "0","0","1","1" };//默认的配置,避免索引越界
                for (int i = 0; i < layoutPosition_.size(); i++) {
                    layoutPosition[i] = layoutPosition_.at(i);
                }
                if (gridLayout) {
                    gridLayout->addWidget(baseWidget, layoutPosition.at(0).toInt(), layoutPosition.at(1).toInt(), layoutPosition.at(2).toInt(), layoutPosition.at(3).toInt());
                }
            }
            else {
                msg.append(QStringLiteral("<%1>节点中存在未解析的自定义类：%2 请检查xml文件和factory派生类\n")
                    .arg(element.tagName())
                    .arg(type));
            }
        }
        else {
            msg.append(QStringLiteral("存在未解析的节点：<%1>\n").arg(element.tagName()));
        }
        element = element.nextSiblingElement();
    }
}
