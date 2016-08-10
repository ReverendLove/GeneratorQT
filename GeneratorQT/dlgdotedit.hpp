#pragma once
#ifndef DLGDOTEDIT_H
#define DLGDOTEDIT_H
#include <QDialog>
#include "ui_dlgdotedit.h"
#include <vector>

class dlgDotEdit : public QDialog, public Ui::dlgDotEdit {
	Q_OBJECT

public:
	dlgDotEdit(QWidget * parent = Q_NULLPTR);
	~dlgDotEdit();

	
	void note_values(std::vector<std::string>& nv){
		QStringList sl;
		for(auto& n : nv){
			QString s = n.c_str();
			sl.push_back(s);
		}		
		cbValue->addItems(sl);
	}

	void gate_values(std::vector<std::string>& nv){
		QStringList sl;
		for(auto& n : nv){
			QString s = n.c_str();
			sl.push_back(s);
		}
		cbGate->addItems(sl);
	}
	void notes(std::vector<std::string>& nv){
		QStringList sl;
		for(auto& n : nv){
			QString s = n.c_str();
			sl.push_back(s);
		}
		cbNote->addItems(sl);
	}

	
	void note(int index){
		cbNote->setCurrentIndex(index);
	}
	
	void gateIndex(int index){
		cbGate->setCurrentIndex(index);
	}

	void velocity(int val){
		slVelocity->setValue(val);
	}

	void timeValue(std::string& s){
		QString qs(s.c_str());
		cbValue->setCurrentIndex(cbValue->findText(qs));
	}

	void gateValue(std::string& s){
		QString qs(s.c_str());
		cbGate->setCurrentIndex(cbGate->findText(qs));
	}


	int note(){
		return cbNote->currentIndex();
	}

	int velocity(){
		return slVelocity->value();
	}

	int timeValueIndex(){
		return cbValue->currentIndex();
	}

	int gateValueIndex(){
		return   cbGate->currentIndex();
	}

public slots:
	void varianzMax(int low){
		slVarianz->setMaximum(127-low);

	}

	void gateMax(int max){
		if(cbGate->currentIndex() > cbValue->currentIndex())
			cbGate->setCurrentIndex(cbValue->currentIndex());
	}

private:
	
};
#endif // DLGDOTEDIT_H