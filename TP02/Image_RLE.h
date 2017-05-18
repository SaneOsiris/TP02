#pragma once
#include <utility>
#include "Pixel_PL.h"
#include "RespecterEcheance.h"
class Image_RLE {
	using VECTOR_T = unsigned char;
private:
	std::vector<std::pair<unsigned int, Pixel_PL>> Image_;//used by PPM2RLE standard
	std::string type;
	unsigned int Width;
	unsigned int Height;
	unsigned int MaxValue;
	bool CorrectPath = false;
	std::vector<VECTOR_T> Data;
	int n = 0;
	Pixel_PL NEW_PIZELLE;
	Pixel_PL OLD_PIZELLE;
	bool fini = false;
public:
	Image_RLE();

	Image_RLE(std::string path);
	/*
	returns true if the compression succeded
	returns false if not(likely caused by a improperly given path)
	*/
	bool PPM2RLE(std::string path);

	/*
	returns true if the compression has finished, and false if not

	*/
	bool PPM2RLE_M(int& iterator, std::vector<std::pair<unsigned int, Pixel_PL>>& Image);

private:
	std::vector<VECTOR_T> getData(std::ifstream& i);
	bool SaveImage(std::string filename);
public:
	bool SaveImage(std::string filename, std::vector<std::pair<unsigned int, Pixel_PL>> img);
};

class INCOMPATIBLE_PIXEL_TYPE {};