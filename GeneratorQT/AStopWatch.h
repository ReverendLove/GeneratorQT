#pragma once
#include <windows.h>

class AStopWatch{
	static LARGE_INTEGER	start, now;
	static LARGE_INTEGER	frequency;
	double	userFrequency;
public:
	enum class unit{ seconds = 1, milliseconds = 1000, microseconds = 1000000 } t_unit;

	AStopWatch(unit u):t_unit{u}{
		QueryPerformanceFrequency(&frequency);	
		userFrequency = frequency.QuadPart / double(t_unit);
	}
	~AStopWatch(){};
	double Start(){
		QueryPerformanceCounter(&start);
		return start.QuadPart / userFrequency;
	}

	double Now(){
		QueryPerformanceCounter(&now);
		return now.QuadPart / userFrequency;
	}

	double Stop(){
		return Now() - start.QuadPart / userFrequency;
	}
};