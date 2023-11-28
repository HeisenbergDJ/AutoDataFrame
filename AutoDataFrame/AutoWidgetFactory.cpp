#include "AutoWidgetFactory.h"

AutoBaseWidget* AutoWidgetFactory::createWidget(const QString& typeName, QDomElement ele, QWidget* parent)
{
    if (typeName == "ACGroupBox") {
        return nullptr;
    }
    if (typeName == "AMLabelLabel") {
        AMLabelLabel* amll = new AMLabelLabel(parent);
        amll->setLabel_L(ele.attribute("label_L"));
        amll->setLabel_R(ele.attribute("label_R"));
        amll->Setname(ele.attribute("name"));
        amll->Setvalue(ele.attribute("value"));
        amll->Setunit(ele.attribute("unit"));
        return amll;
    }
    if (typeName == "AMLabelLine")
    {
        return nullptr;

    }
    if (typeName == "AMLabelLineLabel") {
        AMLabelLineLabel* amlll = new AMLabelLineLabel(parent);
        amlll->setLabel_L(ele.attribute("label_L"));
        amlll->setline_M(ele.attribute("line_M"));
        amlll->setLabel_R(ele.attribute("label_R"));
        amlll->Setname(ele.attribute("name"));
        amlll->Setname(ele.attribute("value"));
        amlll->Setname(ele.attribute("unit"));

        return amlll;
    }
    if (typeName == "AMLabelLineLine")
    {
        return nullptr;
    }
    if (typeName == "AMRadioGroup") {

    }

    return nullptr;
}
