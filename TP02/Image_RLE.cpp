#include "Image_RLE.h"
#include <fstream>
#include <iostream>//TODO remove: debug purposes
#include <iomanip>
#include <string>
using namespace std;
using VECTOR_T = unsigned char;
Image_RLE::Image_RLE()
{

}

Image_RLE::Image_RLE(string path)
{
	ifstream ifs(path, ios::binary);
	if (ifs.is_open())
		if (ifs >> type >> Width >> Height >> MaxValue)
			CorrectPath = true; Data = getData(ifs);
	ifs.close();
}

bool Image_RLE::PPM2RLE(string path)
{
	ifstream ifs(path, ios::binary);
	if (ifs.is_open())
	{
		if (ifs >> type >> Width >> Height >> MaxValue)
		{
			Data = getData(ifs);
			//* TODO remove: cout used for debugging purposes
			cout << "PPM2RLE" << endl;
			cout << "Type : " << type << endl
				<< "Width : " << Width << endl
				<< "Height : " << Height << endl
				<< "MaxValue : " << MaxValue << endl;
			//Real sh*t right here.
			if (Data.size() % BYTES_PER_PIXEL == 0)// Warning if I used "(Data.size()%BYTES_PER_PIXEL)" instead, which I find slightly more attractive, to be honest
			{
				Pixel_PL NEW_PIZELLE;
				Pixel_PL OLD_PIZELLE;
				for (int i = 0, n = 0; i < Data.size() / BYTES_PER_PIXEL; ++i)
				{
					for (int j = 0; j < BYTES_PER_PIXEL; ++j)
					{
						NEW_PIZELLE.colors[j] = Data[i*BYTES_PER_PIXEL + j];
					}
					NEW_PIZELLE.is_null = false;//really supposed to be handled by the Pixel_PL class
					if (OLD_PIZELLE == NEW_PIZELLE || OLD_PIZELLE.is_null)
					{
						n++;
					}
					else
					{
						Image_.push_back(pair<unsigned int, Pixel_PL>(n, NEW_PIZELLE));
						n = 0;
					}
					OLD_PIZELLE = NEW_PIZELLE;
				}
			}
			else
			{
				throw INCOMPATIBLE_PIXEL_TYPE{};
			}
			SaveImage("test");
			//* // debug purposes
			cout << Width << ' ' << Height << endl;
			for (int i = 0; i < Image_.size(); ++i)
			{
				cout << Image_[i].first << ' ';
				unsigned int temp = 0;
				for (int j = 0; j < BYTES_PER_PIXEL; ++j)
				{
					temp += Image_[i].second.colors[j] << j * 8;
					cout << hex << static_cast<int>(Image_[i].second.colors[j]);
					cout << ' ';
				}
				cout << hex << temp << endl;
			}
			//*/
		}
		ifs.close();
		return true;
	}
	else
	{
		ifs.close();//Unecessary if the condition stays as "if(ifs.is_open())" since it would've never been open
		return false;
	}
}

bool Image_RLE::PPM2RLE_M(int& iterator, std::vector<std::pair<unsigned int, Pixel_PL>>& Image)
{		
	//Real sh*t right here.
	if (Data.size() % BYTES_PER_PIXEL == 0)// Warning if I used "(Data.size()%BYTES_PER_PIXEL)" instead, which I find slightly more attractive, to be honest
	{		
		RespecterEcheance echeance((std::chrono::system_clock::duration)200);
		while (echeance() && !fini)
		{
			for (int j = 0; j < BYTES_PER_PIXEL; ++j)
			{
				NEW_PIZELLE.colors[j] = Data[iterator*BYTES_PER_PIXEL + j];
			}
			NEW_PIZELLE.is_null = false;//really supposed to be handled by the Pixel_PL class
			if (OLD_PIZELLE == NEW_PIZELLE || OLD_PIZELLE.is_null)
				n++;//lol
			else
			{
				Image.push_back(pair<unsigned int, Pixel_PL>(n, NEW_PIZELLE));
				n = 0;
			}
			OLD_PIZELLE = NEW_PIZELLE;
			++iterator;
			if (iterator >= Data.size()/BYTES_PER_PIXEL)
				fini = true; n = 0;
		}
		
	}
	else
	{
		throw INCOMPATIBLE_PIXEL_TYPE{};
	}
	return fini;
}

std::vector<VECTOR_T> Image_RLE::getData(ifstream& ifs)
{
	vector<VECTOR_T> v;
	ifs.get();//unused bit
	while (!ifs.eof())
		v.push_back(ifs.get());
	v.pop_back();//remove the end bit
	return v;
}

bool Image_RLE::SaveImage(string filename)
{
	string path = "pictures/" + filename + ".RLE";
	remove(path.c_str());
	ofstream file(path);
	file << Width << ' ' << Height << endl;
	for (int i = 0; i < Image_.size(); ++i)
	{
		file << Image_[i].first << ' ';
		unsigned int temp = 0;
		for (int j = 0; j < BYTES_PER_PIXEL; ++j)
			temp += Image_[i].second.colors[j] << j * 8;
		file << temp << endl;
	}
	return true;
}

bool Image_RLE::SaveImage(std::string filename, std::vector<std::pair<unsigned int, Pixel_PL>> img)
{
	string path = "pictures/" + filename + ".RLE";
	remove(path.c_str());
	ofstream file(path);
	file << Width << ' ' << Height << endl;
	for (int i = 0; i < img.size(); ++i)
	{
		file << img[i].first << ' ';
		unsigned int temp = 0;
		for (int j = 0; j < BYTES_PER_PIXEL; ++j)
			temp += img[i].second.colors[j] << j * 8;
		file << temp << endl;
	}
	return true;
}
