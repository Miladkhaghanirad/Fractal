#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "memory"

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

	Bitmap bitmap(WIDTH,HEIGHT);
	for(int i = 0;i< WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){
			double xFractal = (i - WIDTH/2-200) * 2.0/HEIGHT;
			double yFractal = (j - HEIGHT/2) * 2.0 /HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal,yFractal);
			if(iterations != Mandelbrot::MAX_ITERATIONS){
				histogram[iterations]++;
			}


			uint8_t color =(uint8_t)(256*(double)iterations /Mandelbrot::MAX_ITERATIONS);
			
			color = color * color * color;

			bitmap.setPixel(i,j,0,color,0);

			if(color<min) min = color;
			if(color>max) max = color;
		}
	}
	cout << endl;
	int count = 0;
	for(int i = 0 ;i< Mandelbrot::MAX_ITERATIONS;i++){
		cout << histogram[i] << "  " << flush;
		count += histogram[i];
	}
	cout << endl;
	cout << count << "; " << WIDTH * HEIGHT << endl;


	cout << min << "  was min and max is : " << max << endl;
	bitmap.write("Mandelbrot.bmp");
	cout << "finished" << endl;
	return 0;
}  
