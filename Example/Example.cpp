// Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mgl2/mgl.h>
#include "Header.h"

mglData data1D(101);
mglData data2D(101, 101);
mglData data3D(101, 101, 100);


double *plotting1DArrays(char *function, double xMin, double xMax)
{
	mglGraph *gr = new mglGraph();
	char *title = (char *)malloc(((strlen(function) + 10))*(sizeof(char *)));
	sprintf(title, "     Y = %s;", function);

	gr->SetRanges(xMin, xMax);
	gr->Fill(data1D, function);

	gr->SetRanges(xMin, xMax, data1D.Minimal(), data1D.Maximal());
	gr->Plot(data1D.SubData(-1, 0));
	gr->Text(data1D, title, "k");

	gr->Axis();
	gr->Grid();
	gr->Label('y', "Y", 0);
	gr->Label('x', "X", 0);

	gr->WriteFrame("test1D.bmp");
	free(title);
	return data1D.a;
}

double *plotting2DArrays(char *function, double xMin, double xMax, double yMin, double yMax, double TetX, double TetZ, double TetY)
{
	mglGraph *gr = new mglGraph();

	gr->SetRanges(xMin, xMax, yMin, yMax);
	gr->Fill(data2D, function);
	gr->SetRanges(xMin, xMax, yMin, yMax, data2D.Minimal(), data2D.Maximal());

	//gr->Title(function.c_str());
	gr->Rotate(TetX, TetZ, TetY);

	gr->Box();
	gr->Surf(data2D, "#", "meshnum 10");

	gr->Axis(); gr->Grid();
	gr->Label('x', "X", 0); gr->Label('y', "Y", 1); gr->Label('z', "Z", 1);

	gr->WriteFrame("test3D.bmp");

	return data2D.a;
}

double *plotting3DArrays(char *function, double xMin, double xMax, double yMin, double yMax, double zMin, double zMax, double TetX, double TetZ, double TetY)
{
	mglGraph *gr = new mglGraph();
	
	gr->SetRanges(xMin, xMax, yMin, yMax, zMin, zMax);
	gr->Fill(data3D, function);

	gr->Light(true);
	gr->Alpha(true);
	//gr->Title(function.c_str());
	gr->Rotate(TetX, TetZ, TetY);

	gr->Box();
	gr->Surf3(data3D, "", "value 1");
	gr->Axis(); gr->Grid();
	gr->Label('x', "X", 0); gr->Label('y', "Y", 1); gr->Label('z', "Z", 1);

	gr->WriteFrame("test3D.bmp");
	return data3D.a;
}


//int main() {
//	//double *z = plotting1DArrays("x+1",-5,5);
//
//	//double *z = plotting2DArrays("x^2+y^2", -1, 1, -1, 1, 50, 50, 0);
//
//	double *z = plotting3DArrays("x^2 + y^2 - z",-5,5,-5,5,-5,5,50,50,0);
//
//	system("pause");
//}
