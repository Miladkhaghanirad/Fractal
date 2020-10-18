#include <iostream>
#include "Bitmap.h"

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

	Bitmap bitmap(WIDTH,HEIGHT);
	for(int i = 0;i< WIDTH+1;i++){
		for(int j=0;j<HEIGHT;j++){
			double xFractal = (i - WIDTH/2) * 2.0/WIDTH;
			double yFractal = (j - HEIGHT/2) * 2.0 /HEIGHT;
			if(xFractal<min) min = xFractal;
			if(xFractal>max) max = xFractal;
		}
	}
	cout << min << "  was min and max is : " << max << endl;
	bitmap.write("test.bmp");
	cout << "finished" << endl;
	return 0;
}  
