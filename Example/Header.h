#pragma once

extern "C" __declspec(dllimport) double *plotting1DArrays(char* , double, double);


extern "C" __declspec(dllimport) double *plotting2DArrays(char* , double, double,
	double, double, double, double, double);

extern "C" __declspec(dllimport) double *plotting3DArrays(char* , double, double,
	double, double, double, double, double, double, double);

