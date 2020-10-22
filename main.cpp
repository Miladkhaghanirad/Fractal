#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "memory"
#include <map>
#include "math.h"
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
	int const WIDTH = 800;
	int const HEIGHT = 600;
	double min = 999999;
	double max = -999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{0});
	Bitmap bitmap(WIDTH,HEIGHT);
	for(int i = 0;i< WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){
			double xFractal = (i - WIDTH/2-200) * 2.0/HEIGHT;
			double yFractal = (j - HEIGHT/2) * 2.0 /HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal,yFractal);
			fractal[j*WIDTH+i]= iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}
	for(int i = 0;i< WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;


			int iterations = fractal[j*WIDTH+i];
			if(iterations != Mandelbrot::MAX_ITERATIONS){
			uint8_t color =(uint8_t)(256*(double)iterations /Mandelbrot::MAX_ITERATIONS);
			double hue = 0.0;
			for (int i = 0; i <= iterations; i++)
			{
				hue +=((double) histogram[i])/total;
				/* code */
			}
			
			green = pow(255,hue);
			}
			bitmap.setPixel(i,j,red,green,blue);
		

		}
	}



	cout << endl;
	bitmap.write("Mandelbrot.bmp");
	cout << "finished" << endl;
	return 0;
}  
