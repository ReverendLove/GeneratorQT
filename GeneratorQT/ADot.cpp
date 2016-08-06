/*
  ==============================================================================

	TheDot.cpp
	Created: 15 Jul 2016 6:52:48pm
	Author:  ReverendLove

  ==============================================================================
*/

#include "ADot.h"
int ADot::counter{0};
int ADot::lastId{0};
//std::array<double, 28> ADot::relSpeed = {0.0, 1.0, 1.3333333333, 2.0, 3.0, 2.6666666667, 4.0, 6.0, 5.3333333333, 8.0, 12.0, 10.6666666667, \
//											16.0, 24.0, 21.3333333333, 32.0, 48.0, 64.0, 128.0, 192.0, 256.0, 320.0, 384.0, 448.0, 512.0, \
//											768.0, 1024.0, 2048.0};
std::array<ADot::note_value, 27> speedTable = {ADot::note_value::TNONE, ADot::note_value::T32NDT, ADot::note_value::T32ND, ADot::note_value::T32NDD, \
												ADot::note_value::T16THT, ADot::note_value::T16TH, ADot::note_value::T16THD, ADot::note_value::T8THT, \
												ADot::note_value::T8TH, ADot::note_value::T8THD, ADot::note_value::T4THT, ADot::note_value::T4TH, \
												ADot::note_value::T4THD, ADot::note_value::T2NDT, ADot::note_value::T2ND, ADot::note_value::T2NDD, \
												ADot::note_value::T1, ADot::note_value::T2, ADot::note_value::T3, ADot::note_value::T4, \
												ADot::note_value::T5, ADot::note_value::T6, ADot::note_value::T7, ADot::note_value::T8, \
												ADot::note_value::T12, ADot::note_value::T16, ADot::note_value::T32};

ADot::ADot()
{	counter++;
	id = lastId++;
}

ADot::~ADot()
{	counter--;
}

