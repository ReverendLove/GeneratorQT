/*
  ==============================================================================

	TheDot.h
	Created: 15 Jul 2016
	Author:  ReverendLove

  ==============================================================================
*/

#ifndef ADOT_H_INCLUDED
#define ADOT_H_INCLUDED
#include <string>
#include <array>
#include <utility>
#include <algorithm>
#include <exception>
#include <map>
#include <vector>



class ADot{
public:
	class exception: std::exception{
	};
	
	enum direction{ LEFT, DOWN, RIGHT, UP } dir = UP;
	enum class note_value{	//Alle relativ in Tics angegeben ein Takt hat 96 Tics, ein 1/4-Schlag also 24, bis auf gepunktete 1/32 sind alle exakt.
		TNONE = 0, T32NDT = 2, T32ND = 3, T32NDD = 5 /*gerundet*/, T16THT = 4, T16TH = 6, T16THD = 9, T8THT = 8, T8TH = 12, T8THD = 18, \
		T4THT = 16, T4TH = 24, T4THD = 36, T2NDT = 32, T2ND = 48, T2NDD = 72, T1 = 96, T2 = 192, T3 = 288, T4 = 384, \
		T5 = 480, T6 = 576, T7 = 672, T8 = 768, T12 = 1152, T16 = 1536, T32 = 3072};
	
	

	ADot();
	~ADot();
	int Dir() const{
		return dir;
	}
	int Id(){
		return id;
	}
	unsigned char Pitch(){
		return pitch;
	}
	double Tune(){
		return tune;
	}
	note_value Value() const{ // In Ticks angegeben	
		return value;
	}

	std::string ValueStr() const{
		return valueMap[value];
	}

	note_value Gate() const{
		return gate;
	}
	std::string GateStr() const{
		return valueMap[gate];
	}
	int X() const{
		return x;
	}
	int Y() const{
		return y;
	}
	unsigned char Vel() const{
		return vel;
	}
	unsigned char VelVariance() const{
		return velVariance;
	}
	void Dir(int d) // mit ++increment wird im Uhrzeigersinn gedreht
	{				// es gibt nur vier Richtungen UP, DOWN, LEFT, RIGHT
		dir = (direction)(d % 4);
	}
	void Vel(unsigned char  v){
		vel = v > 127 ? 64 : v;
		velVariance  = velVariance + vel > 127 ? 127 - vel : velVariance;
	}
	void VelVariance(unsigned char  v){
		velVariance  = v + vel > 127 ? 127 - vel : v;
	}
	void Pitch(unsigned char  p){
		pitch = p > 127 ? 81 : p;
	}
	void Tune(double& t){	// tune gibt das Verhältnis zum Viertelton t/1 an
		tune = t <= -1 || t >= 1 ? 0 : t;
	}
	void Value(note_value sp){
		value = sp;
	}
	void Gate(note_value l){
		gate = l;
	}
	bool Plays(){
		return plays;
	}
	void Plays(bool p){
		plays = p;
	}

	void X(int X){
		x = X;
	}

	void Y(int Y){
		y = Y;
	}

	unsigned long long Activated(){
		return activated;
	}

	void Activate(unsigned long long tics){
		activated = tics;
		plays = true;
	}

	void Deactivate(){
		activated = 0;
		plays = false;	
	}

	static int Counter();

private:
	int id{0}, x{0}, y{0};
	unsigned char vel{64};				// Lautstärke / Velocity
	unsigned char velVariance{63};		// Dient als Streuungswert für Vel < 127 
	unsigned char pitch{60};			// Tonhöhe
	double tune{0.0};					// Feinabstimmung der Tonhöhe: Gibt das Verhältnis zum Viertelton t/1 an; also -1 < t < 1
	note_value gate{note_value::T4TH};	// Gatezeit wird in Notenwerten angegeben 
	note_value value{note_value::T4TH};	// Notenwert für die Dauer. Kann von gate abgewürgt werden. 
	bool plays{false};					// Note spielt gerade
	unsigned long long activated{0};	// Zeitpunkt an dem die Note ausgelöst wurde
	
/*
	Static Part
	Methods
*/
public:
	static int indexOfNoteValue(note_value n){
		int i;
		for(i = 0; i < speedTable.size() && n != speedTable[i]; i++){}
		if(i > 26) throw exception();
		return i-1;		
	}

	static note_value noteValue(unsigned int n){
		if(n > speedTable.size())
			throw exception();
		return speedTable[n];
	}
	static std::string& noteValueAsString(note_value n){
		return valueMap[n];
	}
	static std::string& noteName(unsigned int midiNote){
		if(midiNote > midiNotes.size())
			throw exception();
		return midiNotes[midiNote];
	}
	static std::vector<std::string>& timeValueStrings(){
		return timeStrings;
	}

	static std::vector<std::string>& midiNoteStrings(){ //Alle Notennamen für Midinoten 0 - 127
		return midiNotes;								// 0==C0, 60==C6 (Middle C), 127==G10
	}													// 0 wird in manchen Systemen C-2 genannt, 
private:												// In der englischen Notation C-1, deutsch ",,,C"
	/*													// 69 ist Kammerton A (a', 440hz), H statt B
	Static Part
	Properties
	*/

	//////////////////////DON'T FORGET/////////////////////////////////
	// Deklarationsreihenfolge bestimmt die Initialisierungreihenfolge!
	static std::vector<std::string> timeStrings;	// Enthält die Namen aller genutzten Zeitwerte
	static std::array<note_value, 27> speedTable;	// Genutzte Zeitwerte im ganzzahligen Verhältnis zu einem Takt == 96 tics
	static std::map<note_value, std::string> valueMap;	// Assoz. Container um Namen des Zeitwertes zu ermitteln
	static std::map<std::string, note_value> valueAsStringMap;	// Assoz. Container um Namen den Zeitwerte über seinen Namen zu ermitteln
	static std::vector<std::string> midiNotes;	// Die Namen aller Midinoten von 0==C0 - 127==G10
	static std::map<std::string, int> midiNotesStringMap;	// Assoz. Container um mit dem Notennamen den Midiwert zu ermitteln
	static bool initSpeedMap();

	static int counter;	// Anzahl aller Instanzen
	static int lastId;	// Letzte vergebene Id um Eindeutigkeit zu sichern
	static bool staticInit; // Wird zuletzt mit  initSpeedmap, das die valueMap konstruiert, initialisiert
							// timeStrings und speedTabele müssen also schon fertig sein!	
};
#endif  // ADOT_H_INCLUDED