// Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mgl2/mgl.h>
#include <string>
#include "Header.h"
using namespace std;

//
//int plotting1DArrays(string function1,double xMin = -1,double xMax = 1, string function2 = "")
//{
//	mglGraph *gr = new mglGraph;
//	char *title1 = (char *)malloc(((strlen(function1.c_str()) +10 ))*(sizeof(char *)));
//	sprintf(title1, "     Y = %s;",function1.c_str());
//
//	mglData x(101),y(101);
//	double yMax = -10000, yMin=10000;
//	bool isFunction2 = false;
//
//	gr->SetRanges(xMin, xMax);
//	if (strcmp(function2.c_str(), "") != 0) {
//		isFunction2 = true;
//		gr->Fill(y, function2.c_str());
//		yMin = y.Minimal();
//		yMax = y.Maximal();
//	}
//
//	gr->Fill(x, function1.c_str());
//
//	if (yMin > x.Minimal()) yMin = x.Minimal();
//	if (yMax < x.Maximal()) yMax = x.Maximal();
//
//	gr->SetRanges(xMin, xMax,yMin,yMax);
//	gr->Plot(x.SubData(-1, 0));
//	gr->Text(x, title1, "k");
//
//	if (isFunction2) {
//		gr->Plot(y.SubData(-1, 0));
//		char *title2 = (char *)malloc(((strlen(function2.c_str()) + 20))*(sizeof(char *)));
//		sprintf(title2, "                    Y = %s;", function2.c_str());
//		gr->Text(y, title2, "k");
//	}
//
//	gr->Axis();
//	gr->Grid();
//	gr->Label('y', "Y", 0); 
//	gr->Label('x', "X", 0);
//
//	gr->WriteFrame("test.bmp");
//	
//	return 0;
//}

mglData data1D(101);
mglData data2D(101, 101);
mglData data3D(101, 101, 100);


double* plotting1DArrays(string function, double xMin, double xMax)
{
	mglGraph *gr = new mglGraph;
	char *title = (char *)malloc(((strlen(function.c_str()) + 10))*(sizeof(char *)));
	sprintf(title, "     Y = %s;", function.c_str());

	gr->SetRanges(xMin, xMax);
	gr->Fill(data1D, function.c_str());

	gr->SetRanges(xMin, xMax, data1D.Minimal(), data1D.Maximal());
	gr->Plot(data1D.SubData(-1, 0));
	gr->Text(data1D, title, "k");

	gr->Axis();
	gr->Grid();
	gr->Label('y', "Y", 0);
	gr->Label('x', "X", 0);

	gr->WriteFrame("test1D.bmp");

	return data1D.a;
}

double* plotting2DArrays(string function, double xMin, double xMax, double yMin, double yMax, double TetX, double TetZ, double TetY)
{
	mglGraph *gr = new mglGraph;

	gr->SetRanges(xMin, xMax, yMin, yMax);
	gr->Fill(data2D, function.c_str());
	gr->SetRanges(xMin, xMax, yMin, yMax, data2D.Minimal(), data2D.Maximal());

	gr->Title(function.c_str());
	gr->Rotate(TetX, TetZ, TetY);

	gr->Box();
	gr->Surf(data2D, "#", "meshnum 10");

	gr->Axis(); gr->Grid();
	gr->Label('x', "X", 0); gr->Label('y', "Y", 1); gr->Label('z', "Z", 1);

	gr->WriteFrame("test3D.bmp");

	return data2D.a;
}

double *plotting3DArrays(string function, double xMin, double xMax, double yMin, double yMax, double zMin, double zMax, double TetX, double TetZ, double TetY)
{
	mglGraph *gr = new mglGraph;

	gr->SetRanges(xMin, xMax, yMin, yMax, zMin, zMax);
	gr->Fill(data3D, function.c_str());

	gr->Light(true);
	gr->Alpha(true);
	gr->Title(function.c_str());
	gr->Rotate(TetX, TetZ, TetY);

	gr->Box();
	gr->Surf3(data3D, "", "value 1");
	gr->Axis(); gr->Grid();
	gr->Label('x', "X", 0); gr->Label('y', "Y", 1); gr->Label('z', "Z", 1);

	gr->WriteFrame("test3D.bmp");
	return data3D.a;
}


//int main() {
//	//double *z = plotting1DArrays("x+1",0,100);
//
//	double *z = plotting2DArrays("x^2+y^2", -1, 1, -1, 1, 50, 50, 0);
//
//	//double *z = plotting3DArrays("x^2 + y^2 - z");
//	system("pause");
//}
