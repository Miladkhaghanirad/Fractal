#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace milad;

int main(){
	Bitmap bitmap(800,600);
	bitmap.write("test.bmp");
	cout << "finished" << endl;
	return 0;
}  
