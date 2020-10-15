#ifndef BITMAPFILEHEADER_H_
#define BITMAPDILEHEADER_H_
#include <cstdint>
using namespace std;
#pragma pack(2)
namespace milad {
struct BitmapFileHeader{
	char header[2]{'B' , 'M'};
	int32_t fileSize;
	int32_t reserved{0};
	int32_t dataOffset;
};
}
#endif
