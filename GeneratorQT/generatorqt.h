#ifndef GENERATORQT_H
#define GENERATORQT_H

#include <QtWidgets/QMainWindow>
#include "ui_generatorqt.h"
#include "ADot.h"
#include "RtMidi.h"
#include <vector>
#include <string>
#include <chrono>
#include <QTimer>

class GeneratorQT : public QMainWindow
{
	Q_OBJECT

public:
	GeneratorQT(QWidget *parent = 0);
	~GeneratorQT();

public slots:
	void timerEvent();
	void dotsNumChanged();


private:

	Ui::GeneratorQTClass ui;
	
	bool runState{false};
	static unsigned tickCounter;
	static long gSpeed; // Global Speed in BPM
	std::array<std::array<int, 8>, 8> matrix{};
	std::vector<ADot> dots{};

	std::vector<std::string> midiInPorts{};
	std::vector<std::string> midiOutPorts{};
	
	QRect board;
	RtMidiOut* midiOut{nullptr};
	RtMidiIn* midiIn{nullptr};
	QTimer *timer{nullptr};


	static std::chrono::time_point<std::chrono::system_clock>  start;
	
	void paintEvent(QPaintEvent *event);

	static void midiInCallback(double deltatime, std::vector<unsigned char>* message, void * userData);
	void fillMatrix();
	void noteOn(ADot& d);
	int isOccupied(int x, int y){ // Gibt an ob das Feld bereits von einem Stein besetzt ist
		return matrix[x][y];
	}
	void rollPos(ADot& d);

};

#endif // GENERATORQT_H
