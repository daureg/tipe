#ifndef __PNGIMAGE
#define __PNGIMAGE
#include <png.h>
#include <SDL.h>
#include <string>
#include "const.h"
const Uint16 PICTURE_SIZE = MAP_SIZE;
typedef	struct PngImage {
	std::string filename;
	FILE* file;
	png_structp png_ptr;
	png_infop info_ptr;
	png_uint_32 width;
	png_uint_32 height;
	int bit_depth;
	int color_type;
	Uint32 rowbytes;
	Uint8* data;
} PngImage;
#endif
