#include "generatorqt.h"
#include <QPainter>


unsigned GeneratorQT::tickCounter{0};
long GeneratorQT::gSpeed{0}; // Global Speed in BPM
std::chrono::time_point<std::chrono::system_clock>  GeneratorQT::start = std::chrono::system_clock::now();

GeneratorQT::GeneratorQT(QWidget *parent)
	: QMainWindow(parent)
{
	srand(unsigned(time(0)));
	
	for(int i = 0; i < 2; i++){
		ADot d;
		d.X(rand() % 8);
		d.Y(rand() % 8);
		d.Dir(rand() % 4);
		d.Pitch(32 + rand() % 50);
		d.Vel((27 + rand() % 100));
		dots.push_back(d);
	}
	fillMatrix();
	//mainTimer->Interval = 21;

	try{
		midiOut = new RtMidiOut();
	}
	catch(RtMidiError &error){
		error.printMessage();
		exit(EXIT_FAILURE);
	}

	try{
		midiIn = new RtMidiIn();
	}
	catch(RtMidiError &error){
		error.printMessage();
		exit(EXIT_FAILURE);
	}

	int nInPorts = midiIn->getPortCount();
	for(int i = 0; i < nInPorts; i++){
		midiInPorts.push_back(midiIn->getPortName(i));
	}
		midiIn->openPort(0);

	int nOutPorts = midiOut->getPortCount();
	for(int i = 0; i < nOutPorts; i++){
		midiOutPorts.push_back(midiOut->getPortName(i));
	}
	midiOut->openPort(0);
	
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &GeneratorQT::timerEvent);
	timer->setTimerType(Qt::PreciseTimer);
	timer->start(21);
	// Qt-User-Interface wird initialisiert
	ui.setupUi(this);
}

GeneratorQT::~GeneratorQT(){
	if(timer != nullptr){
		delete timer;
		timer = nullptr;
	}
	if(midiIn != nullptr){
		midiIn->closePort();
		delete midiIn;
		midiIn = nullptr;
	}
	if(midiOut != nullptr){
		midiOut->closePort();
		delete midiOut;
		midiOut = nullptr;
	}
}

void GeneratorQT::dotsNumChanged(){
	if(dots.size() == ui.sbNumberOfDots->value())
		return;
	if(dots.size() < ui.sbNumberOfDots->value()){		
		for(int i = dots.size(); i < ui.sbNumberOfDots->value(); i++){
			ADot d;
			d.X(rand() % 8);
			d.Y(rand() % 8);
			d.Dir(rand() % 4);
			d.Pitch(32 + rand() % 50);
			d.Vel((27 + rand() % 100));
			dots.push_back(d);
			matrix[d.X()][d.Y()] = 1;
		}
	}
	else{
		for(int i = dots.size(); i > ui.sbNumberOfDots->value(); i--){
			ADot & d = dots.back();
			matrix[d.X()][d.Y()] = 0;
			dots.pop_back();
		}
	}
	update();
}

void GeneratorQT::timerEvent(){
	for(ADot& d : dots){
		if(tickCounter % unsigned int(d.Speed()) == 0){
			int x = d.X();
			int y = d.Y();
			switch(d.Dir()){
			case ADot::RIGHT:
				if(x == 7){
					d.Dir(ADot::LEFT);
					noteOn(d);
				}
				else{
					if(!isOccupied(x + 1, y))
						d.X(x + 1);
					else
						rollPos(d);
				}
				break;
			case ADot::LEFT:
				if(d.X() == 0){
					d.Dir(ADot::RIGHT);
					noteOn(d);
				}
				else{
					if(!isOccupied(x - 1, y))
						d.X(x - 1);
					else
						rollPos(d);
				}
				break;
			case ADot::DOWN:
				if(y == 7){
					d.Dir(ADot::UP);
					noteOn(d);
				}
				else{
					if(!isOccupied(x, y + 1))
						d.Y(y + 1);
					else
						rollPos(d);
				}
				break;
			case ADot::UP:
				if(y == 0){
					d.Dir(ADot::DOWN);
					noteOn(d);
				}
				else{
					if(!isOccupied(x, y - 1))
						d.Y(y - 1);
					else
						rollPos(d);
				}
				break;
			}
			matrix[x][y] = 0;
		}
		matrix[d.X()][d.Y()] = 1;
		update();
	}
	tickCounter++;
	fillMatrix();
}

void GeneratorQT::paintEvent(QPaintEvent *event){
	QMainWindow::update();
	
	QPainter p(this);
	QRect rect = ui.wdgCentral->rect();
	int x = rect.left();
	int y = rect.top() + ui.mainToolBar->height() + ui.menuBar->height();
	
	board = QRect(x,y,400,400);
	p.fillRect(board, QColor(255,255,220));
	
	QColor color(85, 85, 50); //Dunkle Felder
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			p.fillRect((j % 2 == 1 ? 50 : 0) + x + i * 100, y + j * 50, 50, 50, color);
		}
	}

	p.setPen(Qt::red);
	p.setBrush(Qt::red);
	for(ADot& d : dots){
		p.drawEllipse(QRect(x + 5 + d.X() * 50, y + 5 + d.Y() * 50, 40, 40));
	}	
}

void GeneratorQT::midiInCallback(double deltatime, std::vector<unsigned char>* message, void * userData){
	std::chrono::nanoseconds delta;
	unsigned long nCounter{};
	// Hier wird bei jedem MidiInEvent etwas gemacht.
	if(message->size() > 0){
		switch((*message)[0]){
		case 248:
			if(nCounter == 0){
				start = std::chrono::system_clock::now();
			}
			if(nCounter % 24 == 0){ //Durchschnitt für 24 Ticks berechnen
				delta = std::chrono::system_clock::now() - start;
				gSpeed = delta.count() / (1000000 * 24); // msec für einen Tick in static-Variablen gSpeed ablegen
			}
			nCounter++;
			break;
		case 144:	// Note On / Achtung! Kanalnummer berücksichtigen.
		case 128:	// Note Off / Achtung! Kanalnummer berücksichtigen.
		case 176:	// Controller / Achtung! Kanalnummer berücksichtigen.
			break;
		}
	}
}

void GeneratorQT::fillMatrix(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			matrix[i][j] = 0; 
		}
	}
	for(ADot &d : dots){
		matrix[d.X()][d.Y()] = 1;
	}
}

void GeneratorQT::noteOn(ADot& d){
	std::vector<unsigned char> mgv;

	mgv.push_back('\x90');
	mgv.push_back(d.Pitch());
	mgv.push_back(d.Vel());

	midiOut->sendMessage(&mgv);
}

void GeneratorQT::rollPos(ADot & d){
	// Anfangspunkt für die Suche nach einem freien Feld ist diagonal untn rechts
	// Bei Überschreiten der Spielfeldgrenzen wird ganz links und/oder ganz oben
	// mit der Suche begonnen.
	int ix{(d.X() + 1) % 8};
	int jy{(d.Y() + 1) % 8};
	bool success{false};
	for(int i = ix; i < 8 + ix; i++){
		for(int j = jy; j < 8 + jy; j++){
			if(matrix[i % 8][j % 8] == 0){
				d.X(i % 8);
				d.Y(j % 8);
				d.Dir(d.Dir() + 1); // Im Uhrzeigersinn drehen
				matrix[i % 8][j % 8] = 1;
				success = true;
				break;
			}
		}
	}
	// Falls alle Stricke reißen und kein freier Platz gefunden wurde
	// (Sehr unwahrscheinlich!)
	if(!success){
		d.X(rand() % 8);
		d.X(rand() % 8);
		d.Dir(d.Dir() + 1); // Im Uhrzeigersinn drehen
	}
}