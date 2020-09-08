#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)
namespace milad{
struct BitmapInfoHeader {

	int32_t headersize{40};
	int32_t width;
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24};
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};//Bits per Pixel
	int32_t verticalResolution{2400};//Bist per Pixel
	int32_t color{0};
	int32_t importantColors{0};



};



}


#endif
