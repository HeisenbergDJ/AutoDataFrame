#include "AMLabelLabel.h"

AMLabelLabel::AMLabelLabel(QWidget *parent)
	: AutoBaseWidget(parent)
{
	label_L = new QLabel;
	label_R = new QLabel;
	hl = new QHBoxLayout(this);
	this->setLayout(hl);
	hl->addWidget(label_L);
	hl->addWidget(label_R);
}

AMLabelLabel::~AMLabelLabel()
{

}
