/*
  ==============================================================================

	TheDot.cpp
	Created: 15 Jul 2016 6:52:48pm
	Author:  ReverendLove

  ==============================================================================
*/

#include "ADot.h"
#include <exception>
#include <iostream>

std::array<ADot::note_value, 27> ADot::speedTable{ADot::note_value::TNONE, ADot::note_value::T32NDT, ADot::note_value::T32ND, ADot::note_value::T32NDD, \
													ADot::note_value::T16THT, ADot::note_value::T16TH, ADot::note_value::T16THD, ADot::note_value::T8THT, \
													ADot::note_value::T8TH, ADot::note_value::T8THD, ADot::note_value::T4THT, ADot::note_value::T4TH, \
													ADot::note_value::T4THD, ADot::note_value::T2NDT, ADot::note_value::T2ND, ADot::note_value::T2NDD, \
													ADot::note_value::T1, ADot::note_value::T2, ADot::note_value::T3, ADot::note_value::T4, \
													ADot::note_value::T5, ADot::note_value::T6, ADot::note_value::T7, ADot::note_value::T8, \
													ADot::note_value::T12, ADot::note_value::T16, ADot::note_value::T32};

std::vector<std::string> ADot::timeStrings{"Random", "1/32T", "1/32", "1/32*", "1/16T", "1/16", "1/16*", "1/8T", "1/8", "1/8*", "1/4T", "1/4", "1/4*", \
											"1/2T", "1/2", "1/2*", "1/1", "2/1", "3/1", "4/1", "5/1", "6/1", "7/1", "8/1", "12/1", "16/1", "32/1"};

std::map<ADot::note_value, std::string> ADot::valueMap{};
std::map<std::string, ADot::note_value> ADot::valueAsStringMap{};
std::vector<std::string> ADot::midiNotes;
std::map<std::string, int> ADot::midiNotesStringMap;

int ADot::counter{0};
int ADot::lastId{0};

bool ADot::staticInit = ADot::initSpeedMap();

int ADot::Counter(){
	return counter;
}


bool ADot::initSpeedMap(){
	try{
		for(int i = 0; i < timeStrings.size() && i < speedTable.size(); i++){
			valueMap.insert(std::make_pair(ADot::speedTable[i], ADot::timeStrings[i]));
			valueAsStringMap.insert(std::make_pair(ADot::timeStrings[i], ADot::speedTable[i]));
		}
		std::vector<std::string> twelve{"C", "C#", "D", "D#", "E", "F", "F#", "G", "Ab", "A", "Bb", "H"};
		for(int i = 0; i < 128; i++){
			std::string s = twelve[i % 12];
			if(i < 120)
				s += char('0' + i / 12);
			else
				s += "10";
			midiNotes.push_back(s);
			midiNotesStringMap.insert(std::make_pair(s, i));
		}			
	}
	catch(std::exception& ex){
		std::cerr << "Exception in ADot::initSpeedmap(): " << ex.what() << std::endl;
		return false;
	}
	return true;
}


ADot::ADot()
{	counter++;
	id = lastId++;
}

ADot::~ADot()
{	counter--;
}

