#pragma once
#include "autodataframe_global.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "AutoBaseWidget.h"

class AUTODATAFRAME_EXPORT AMLabelLineLabel : public AutoBaseWidget
{
	Q_OBJECT

public:
	AMLabelLineLabel(QWidget* parent = nullptr);
	~AMLabelLineLabel();
	QString getLabel_L() { return label_L->text(); }
	QString getline_M() { return line_M->text(); }
	QString getLabel_R() { return label_R->text(); }
	void setLabel_L(QString str) { label_L->setText(str); }
	void setline_M(QString str) { line_M->setText(str); }
	void setLabel_R(QString str) { label_R->setText(str); }

private:
	QLabel* label_L = nullptr;
	QLineEdit* line_M = nullptr;
	QLabel* label_R = nullptr;
	QHBoxLayout* hl = nullptr;
};
