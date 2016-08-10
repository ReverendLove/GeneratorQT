/*
  ==============================================================================

	TheDot.h
	Created: 15 Jul 2016 6:52:48pm
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
	enum class note_value{
		TNONE = 0, T32NDT = 2, T32ND = 3, T32NDD = 5, T16THT = 4, T16TH = 6, T16THD = 9, T8THT = 8, T8TH = 12, T8THD = 18, \
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
	note_value Speed() const{ // In Ticks angegeben	
		return value;
	}

	std::string SpeedStr() const{
		return valueMap[value];
	}

	note_value Length() const{
		return length;
	}
	std::string LengthStr() const{
		return valueMap[length];
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
	void Dir(int d) // mit ++increment wird im Uhrzeigersinn gedreht
	{
		dir = (direction)(d % 4);
	}
	void Vel(int v){
		vel = v;
	}
	void Pitch(int p){
		pitch = p;
	}
	void Speed(note_value sp){
		value = sp;
	}
	void Length(note_value l){
		length = l;
	}
	void X(int X){
		x = X;
	}
	void Y(int Y){
		y = Y;
	}
private:
	int id{0}, x{0}, y{0};
	unsigned char vel{64};
	unsigned char pitch{60};
	note_value length{note_value::T4TH};
	note_value value{note_value::T4TH};
	//////////////////////DON'T FORGET/////////////////////////////////
	// Deklarationsreihenfolge bestimmt die Initialisierungreihenfolge!
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

	static std::vector<std::string>& midiNoteStrings(){
		return midiNotes;
	}
private:
	static std::vector<std::string> timeStrings;
	static std::array<double, 27> relSpeed;
	static std::array<note_value, 27> speedTable;
	static std::map<note_value, std::string> valueMap;
	static std::map<std::string, note_value> valueAsStringMap;
	static std::vector<std::string> midiNotes;
	static std::map<std::string, int> midiNotesStringMap;
	static bool initSpeedMap();

	static int counter;
	static int lastId;
	static bool staticInit; // Wird zuletzt mit  initSpeedmap, das die valueMap konstruiert, initialisiert
							// timeStrings und speedTabele müssen also schon fertig sein!	


};
#endif  // ADOT_H_INCLUDED
