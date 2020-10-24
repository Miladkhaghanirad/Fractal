#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace std;
using namespace milad;

int main(){
	
	FractalCreator fractalcreator(800,600);
	fractalcreator.addRange(0.0,RGB(0,0,0));
	fractalcreator.addRange(0.3,RGB(255,0,0));
	fractalcreator.addRange(0.5,RGB(255,255,0));
	fractalcreator.addRange(1.0,RGB(255,255,255));
	fractalcreator.addZoom(Zoom(295,202,0.1));
	fractalcreator.addZoom(Zoom(312,304,0.1));
	fractalcreator.run("Mandelbrot.bmp");
	
	
	cout << "finished" << endl;
	return 0;
}  
