#include "AMLabelLineLabel.h"

AMLabelLineLabel::AMLabelLineLabel(QWidget* parent)
	: AutoBaseWidget(parent)
{
	label_L = new QLabel;
	line_M = new QLineEdit;
	label_R = new QLabel;
	hl = new QHBoxLayout(this);
	this->setLayout(hl);
	hl->addWidget(label_L);
	hl->addWidget(line_M);
	hl->addWidget(label_R);
	connect(line_M, &QLineEdit::textChanged, this, [=] {
		this->Setvalue(line_M->text());
		});
}

AMLabelLineLabel::~AMLabelLineLabel()
{

}
