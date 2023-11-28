#include "TestDemo.h"
#include "AutoDataFrame.h"
#include "AutoWidgetFactory.h"
//#include "ACGroupBox.h"
//#include "AMLabelLabel.h"
TestDemo::TestDemo(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	//�Զ�widget�������ɣ��������ݵģ�
	AutoDataFrame* myFrame = new AutoDataFrame(this);
	AutoWidgetFactory* myFactory = new AutoWidgetFactory;
	myFrame->setFactory(myFactory);
	QString msg;
	QWidget* certainWidget = myFrame->getWidgetfromAutoData("D:/PERA/AutoDataFrame/AutoDataFrame/x64/Debug/config/autodata.xml", msg);
	QGridLayout* glayout = new QGridLayout(this);
	this->setLayout(glayout);
	glayout->addWidget(certainWidget);
	QMap<QString, QVariant> p_widgetMap = myFrame->getAutoWidgetMap();
	QMap<QString, QVariant> p_AMMap = myFrame->getAutoWidgetMap();

}

TestDemo::~TestDemo()
{}
