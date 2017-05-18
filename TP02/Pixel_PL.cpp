#include "Pixel_PL.h"

Pixel_PL::Pixel_PL(VECTOR_T r, VECTOR_T g, VECTOR_T b) {
	colors.resize(BYTES_PER_PIXEL);
	is_null = false;
	//TODO possibility to not check the color value in favor of speed
	r >= 0 && r <= 255 ? colors[0] = r : is_null = true;
	g >= 0 && g <= 255 ? colors[1] = g : is_null = true;
	b >= 0 && b <= 255 ? colors[2] = b : is_null = true;
}

Pixel_PL::Pixel_PL(const Pixel_PL & P) {
	colors = P.colors;
	is_null = P.is_null;
}

void Pixel_PL::operator=(const Pixel_PL& P) {
	colors = P.colors;
	is_null = P.is_null;
}

bool Pixel_PL::operator==(const Pixel_PL & P)
{
	return colors == P.colors && is_null == P.is_null;
}

bool Pixel_PL::operator!=(const Pixel_PL & P)
{
	return !(colors == P.colors && is_null == P.is_null);
}

Pixel_PL::~Pixel_PL() {

}
