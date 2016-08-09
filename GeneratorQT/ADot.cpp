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

int ADot::counter{0};
int ADot::lastId{0};
std::array<double, 27> ADot::relSpeed{0.0, 2.0, 3.0, 2.6666666667, 4.0, 6.0, 5.3333333333, 8.0, 12.0, 10.6666666667, \
										16.0, 24.0, 21.3333333333, 32.0, 48.0, 64.0, 128.0, 192.0, 256.0, 320.0, 384.0, 448.0, 512.0, \
										768.0, 1024.0, 2048.0};

std::array<ADot::note_value, 27> ADot::speedTable{ADot::note_value::TNONE, ADot::note_value::T32NDT, ADot::note_value::T32ND, ADot::note_value::T32NDD, \
													ADot::note_value::T16THT, ADot::note_value::T16TH, ADot::note_value::T16THD, ADot::note_value::T8THT, \
													ADot::note_value::T8TH, ADot::note_value::T8THD, ADot::note_value::T4THT, ADot::note_value::T4TH, \
													ADot::note_value::T4THD, ADot::note_value::T2NDT, ADot::note_value::T2ND, ADot::note_value::T2NDD, \
													ADot::note_value::T1, ADot::note_value::T2, ADot::note_value::T3, ADot::note_value::T4, \
													ADot::note_value::T5, ADot::note_value::T6, ADot::note_value::T7, ADot::note_value::T8, \
													ADot::note_value::T12, ADot::note_value::T16, ADot::note_value::T32};

std::vector<std::string> ADot::timeStrings{"Random", "1/32T", "1/32", "1/32*", "1/16T", "1/16", "1/16*", "1/8T", "1/8", "1/8*", "1/4T", "1/4", "1/4*", \
											"1/2T", "1/2", "1/2*", "1/1", "1/2", "1/3", "1/4", "1/5", "1/6", "1/7", "1/8", "1/12", "1/16", "1/32"};

std::map<ADot::note_value, std::string> ADot::valueMap{};
bool ADot::staticInit = ADot::initSpeedMap();

bool ADot::initSpeedMap(){
	try{
		for(int i = 0; i < timeStrings.size() && i < speedTable.size(); i++){
			valueMap.insert(std::make_pair(ADot::speedTable[i], ADot::timeStrings[i]));
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

