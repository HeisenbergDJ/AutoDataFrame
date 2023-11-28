#pragma once
#include "autodataframe_global.h"
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "AutoBaseWidget.h"

class AUTODATAFRAME_EXPORT AMLabelLabel : public AutoBaseWidget
{
	Q_OBJECT

public:
	AMLabelLabel(QWidget* parent = nullptr);
	~AMLabelLabel();
	QString getLabel_L() { return label_L->text(); }
	QString getLabel_R() { return label_R->text(); }
	void setLabel_L(QString str) { label_L->setText(str); }
	void setLabel_R(QString str) { label_R->setText(str); }


private:
	QLabel* label_L = nullptr;
	QLabel* label_R = nullptr;
	QHBoxLayout* hl = nullptr;
};
