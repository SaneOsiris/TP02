#include "Image_RLE.h"
#include <iostream>
using namespace std;
int main()
{
	//*
	string path = "pictures/test2.ppm";
	Image_RLE img;
	
	if (img.PPM2RLE(path))
	{
		cout << "Worked" << endl;
	}
	else
	{
		cout << "nope" << endl;
	}
	//*/
	//*
	std::vector<std::pair<unsigned int, Pixel_PL>> Image_m;
	Image_RLE img_m(path);
	int iterator = 0;
	img_m.PPM2RLE_M(iterator, Image_m);
	while (!img_m.PPM2RLE_M(iterator, Image_m)) {
		
	}
	img_m.SaveImage("sayWhat", Image_m);
	//*/
}
