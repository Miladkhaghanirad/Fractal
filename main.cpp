#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "memory"
#include <map>
#include "math.h"
#include "ZoomList.h"
#include "FractalCreator.h"

using namespace std;
using namespace milad;
int getcolor(int i){
	int res;
	res = i *10 ;
	if (res > 255)
		res = res - 255;

	return res;
}

int main(){
	int height = 600;


	FractalCreator fractalcreator(800,600);
	
	
	fractalcreator.addZoom(Zoom(451,height-300,0.1));
	//fractalcreator.addZoom(Zoom(392,height-300,0.1));
	fractalcreator.calculateIteration();
	fractalcreator.calculateTotalIterations();
	fractalcreator.drawFractal();
	fractalcreator.writeBitmap("Mandelbrot.bmp");
	cout << "finished" << endl;
	return 0;
}  
