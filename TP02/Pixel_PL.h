#pragma once
#include <vector>
static const int BYTES_PER_PIXEL = 3;
struct Pixel_PL
{
	using VECTOR_T = unsigned char;
	bool is_null;	
	std::vector<VECTOR_T> colors;
	const VECTOR_T DARKEST_HUE = 0;//to have a 4-byte pixel
	Pixel_PL() { is_null = true; colors.resize(BYTES_PER_PIXEL); }
	Pixel_PL(VECTOR_T r, VECTOR_T g, VECTOR_T b);
	Pixel_PL(const Pixel_PL& P);
	void operator=(const Pixel_PL& P);
	bool operator==(const Pixel_PL& P);
	bool operator!=(const Pixel_PL& P);
	~Pixel_PL();
};

