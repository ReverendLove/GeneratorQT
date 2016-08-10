#include "generatorqt.h"
#include "dlgdotedit.hpp"
#include <QPainter>
#include <algorithm>


unsigned GeneratorQT::tickCounter{0};
long GeneratorQT::gSpeed{0}; // Global Speed in BPM
std::chrono::time_point<std::chrono::system_clock>  GeneratorQT::start = std::chrono::system_clock::now();

GeneratorQT::GeneratorQT(QWidget *parent)
	: QMainWindow(parent)
{
	srand(unsigned(time(0)));
	
	for(int i = 0; i < 2; i++){
		ADot d;
		pushDot(d, true);		
	}
	fillMatrix();
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
	timer->start(bpm_to_msec_per_tic(120));
	// Qt-User-Interface wird initialisiert
	ui.setupUi(this);
	ui.sbNumberOfDots->setValue(2);
	ui.slSpeed->setValue(120);
	fillDotsTable();
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
	if(dots.size() < ui.sbNumberOfDots->value()){		
		for(int i = dots.size(); i < ui.sbNumberOfDots->value(); i++){
			ADot d;
			pushDot(d, true);
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
	fillDotsTable();
	update();
}

void GeneratorQT::slSpeedChanged(int b){
	if(timer!=nullptr)
		timer->start(bpm_to_msec_per_tic(b));
}

void GeneratorQT::editDot(){
	dlgDotEdit dEdit(this);
	
	int t_row = ui.tblDots->currentRow();
	int nActiveDot = ui.tblDots->item(t_row, 0)->text().toInt(); // In der ersten Spalte (0) steht die Id des ADots
	auto di = std::find_if(dots.begin(), dots.end(), [&nActiveDot](ADot& a) -> bool{return a.Id() == nActiveDot; });
	ADot& ad = *di;
	dEdit.note_values(ADot::timeValueStrings());
	dEdit.gate_values(ADot::timeValueStrings());
	dEdit.notes(ADot::midiNoteStrings());
	dEdit.note(ad.Pitch());
	dEdit.velocity(ad.Vel());
	dEdit.timeValue(ADot::noteValueAsString(ad.Value()));
	dEdit.gateValue(ADot::noteValueAsString(ad.Gate()));
	if(dEdit.exec() == QDialog::Accepted){
		ad.Pitch(dEdit.note());
		ad.Value(ADot::noteValue(dEdit.timeValueIndex()));
		ad.Gate(ADot::noteValue(dEdit.gateValueIndex()));
		ad.Vel(dEdit.velocity());
		
		//ui.tblDots->setItem(t_row, 0, new QTableWidgetItem(tr("%1").arg(ad.Id())));
		ui.tblDots->setItem(t_row, 1, new QTableWidgetItem(tr("%1").arg(ADot::noteName(ad.Pitch()).c_str())));
		ui.tblDots->setItem(t_row, 2, new QTableWidgetItem(tr(ad.ValueStr().c_str())));
		ui.tblDots->setItem(t_row, 3, new QTableWidgetItem(tr(ad.GateStr().c_str())));
		ui.tblDots->setItem(t_row, 4, new QTableWidgetItem(tr("%1").arg(ad.Vel())));
	}	
}

void GeneratorQT::timerEvent(){
	for(ADot& d : dots){
		unsigned int nValue = d.Value() == ADot::note_value::TNONE ? rand() % 48 + 8 : unsigned int(d.Value());
		unsigned int nGate = d.Gate() == ADot::note_value::TNONE ? rand() % 48 + 8 : unsigned int(d.Gate());
		
		if(d.Plays() && tickCounter >= d.Activated() + unsigned long long(d.Gate()))
			noteOff(d);
		if( tickCounter % nValue == 0){
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
		}
		matrix[d.X()][d.Y()] = 1;
		update();
	}
	tickCounter++;
	fillMatrix();
}

void GeneratorQT::paintEvent(QPaintEvent *event){
	QMainWindow::update();
	
	// Schachbrett zeichnen
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

	// ADots ("Spielsteine") zeichnen
	p.setBrush(Qt::red);
	QPoint pt;
	for(ADot& d : dots){
		p.setPen(Qt::red);
		p.drawEllipse(QRect(x + 5 + d.X() * 50, y + 5 + d.Y() * 50, 40, 40));
		p.setPen(Qt::black);
		pt.setX(x + 12 + d.X() * 50);
		pt.setY(y + 25 + d.Y() * 50);
		QString sId; 
		sId.setNum(d.Id());
		p.drawText(pt, sId);
	}

	// Durch Anwender ausgewählten Spielstein gelb zeichnen
	if(!ui.tblDots->selectedItems().isEmpty()){ // Ist eine Zeile in der Tabelle ausgewählt?
		int t_row = ui.tblDots->currentRow();
		int nActiveDot = ui.tblDots->item(t_row, 0)->text().toInt(); // In der ersten Spalte (0) steht die Id des ADots
		auto di = std::find_if(dots.begin(), dots.end(), [&nActiveDot](ADot& a) -> bool {return a.Id() == nActiveDot; });
		ADot& ad = *di;
		// Ausgewählter ADot wird gelb
		p.setBrush(Qt::yellow);
		p.setPen(Qt::yellow);
		p.drawEllipse(QRect(x + 5 + ad.X() * 50, y + 5 + ad.Y() * 50, 40, 40));
		p.setPen(Qt::black);
		pt.setX(x + 12 + ad.X() * 50);
		pt.setY(y + 25 + ad.Y() * 50);
		QString sId;
		sId.setNum(ad.Id());
		p.drawText(pt, sId);
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
				gSpeed = round(delta.count() / (1000000 * 24)); // msec für einen Tick in static-Variablen gSpeed ablegen
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
	d.Activate(tickCounter);
}

void GeneratorQT::noteOff(ADot & d){
	std::vector<unsigned char> mgv;

	mgv.push_back('\x80');
	mgv.push_back(d.Pitch());
	midiOut->sendMessage(&mgv);
	d.Deactivate();
}

void GeneratorQT::rollPos(ADot & d){
	// Anfangspunkt für die Suche nach einem freien Feld ist einer Springerbewegung beim Schach gleich
	// Bei Überschreiten der Spielfeldgrenzen wird ganz links und/oder ganz oben
	// mit der Suche begonnen.
	int ix, jy;
	switch(d.Dir()){
	case ADot::UP:
		ix = (d.X() + 1) % 8;
		jy = d.Y() > 1 ? (d.Y() - 2) % 8 : (d.Y() + 7) % 8;
		break;
	case ADot::DOWN:
		ix = d.X() > 0 ? (d.X() - 1) % 8 : 7;
		jy = (d.Y() + 2) % 8;
		break;
	case ADot::LEFT:
		ix = (d.X() + 2) % 8;
		jy = (d.Y() + 1) % 8;
		break;
	case ADot::RIGHT:
		ix = d.X() > 1 ? (d.X() - 2) % 8 : (d.X() + 7) % 8;;
		jy = (d.Y() + 1) % 8;
		break;
	}
	
	
	bool success{false};
	for(int i = ix; i < 8 + ix; i++){
		for(int j = jy; j < 8 + jy; j++){
			if(matrix[i % 8][j % 8] == 0){
				d.X(i % 8);
				d.Y(j % 8);		
				d.Dir(rand()%4); // Im Uhrzeigersinn drehen
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

void GeneratorQT::pushDot(ADot & d, bool randomly){
	if(randomly == true){
		d.X(rand() % 8);
		d.Y(rand() % 8);
		d.Dir(rand() % 4);
		d.Pitch(32 + rand() % 50);
		d.Vel((27 + rand() % 100));
	}
	dots.push_back(d);	
}

void GeneratorQT::fillDotsTable(){
	int r = 0;
	ui.tblDots->clearContents();
	for(ADot& d : dots){		
		ui.tblDots->setItem(r, 0, new QTableWidgetItem(tr("%1").arg(d.Id())));
		ui.tblDots->setItem(r, 1, new QTableWidgetItem(tr("%1").arg(ADot::noteName(d.Pitch()).c_str())));
		ui.tblDots->setItem(r, 2, new QTableWidgetItem(tr(d.ValueStr().c_str())));
		ui.tblDots->setItem(r, 3, new QTableWidgetItem(tr(d.GateStr().c_str())));
		ui.tblDots->setItem(r, 4, new QTableWidgetItem(tr("%1").arg(d.Vel())));
		r++;
	}	
}