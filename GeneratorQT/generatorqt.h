#ifndef GENERATORQT_H
#define GENERATORQT_H
#include <windows.h>
#include <QtWidgets/QMainWindow>
#include "ui_generatorqt.h"
#include "ADot.h"
#include "RtMidi.h"
#include <vector>
#include <string>
#include <chrono>
#include <QTimer>
#include <math.h>

class GeneratorQT : public QMainWindow
{
	Q_OBJECT

public:
	GeneratorQT(QWidget *parent = 0);
	~GeneratorQT();

	int bpm_to_msec_per_tic(int bpm = 120){
		double dmsec = (dmsec = 2500 / bpm);
		return round(dmsec);
	};


public slots:
	void timerEvent();
	void dotsNumChanged();
	void slSpeedChanged(int);
	void editDot();
	void startStop(bool);
	void midiInChanged(int);
	void midiOutChanged(int);
	void externalSync(bool);


private:

	Ui::GeneratorQTClass ui;
	
	bool runState{false};
	static unsigned tickCounter;
	static unsigned long long gSpeed; // Global Speed in BPM
	static unsigned long long callBackCounter;
	static LARGE_INTEGER start, 
						end, 
						elapsedMicroseconds,
						frequency;

	std::array<std::array<int, 8>, 8> matrix{};
	std::vector<ADot> dots{};

	QStringList midiInPorts{};
	QStringList midiOutPorts{};
	
	QRect board;
	RtMidiOut* midiOut{nullptr};
	RtMidiIn* midiIn{nullptr};
	QTimer *timer{nullptr};


	void paintEvent(QPaintEvent *event);

	static void midiInCallback(double deltatime, std::vector<unsigned char>* message, void * userData);
	void fillMatrix();
	void noteOn(ADot& d);
	void noteOff(ADot& d);
	int isOccupied(int x, int y){ // Gibt an ob das Feld bereits von einem Stein besetzt ist
		return matrix[x][y];
	}
	void rollPos(ADot& d);
	void pushDot(ADot&d, bool randomly = false);

	void fillDotsTable();

};

#endif // GENERATORQT_H
