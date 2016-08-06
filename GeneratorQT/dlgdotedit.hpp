#pragma once
#ifndef DLGDOTEDIT_H
#define DLGDOTEDIT_H
#include <QDialog>
#include "ui_dlgdotedit.h"

class dlgDotEdit : public QDialog, public Ui::dlgDotEdit {
	Q_OBJECT

public:
	dlgDotEdit(QWidget * parent = Q_NULLPTR);
	~dlgDotEdit();

private:
	
};
#endif // DLGDOTEDIT_H