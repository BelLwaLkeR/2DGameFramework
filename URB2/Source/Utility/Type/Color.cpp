#include "Color.h"
#include <Source/Framework/Define.h>

float util::Color::getRedF() const{
	return static_cast<float>(R) / INTCOLOR_MAX;
}

float util::Color::getGreenF() const {
	return static_cast<float>(G) / INTCOLOR_MAX;
}

float util::Color::getBlueF() const {
	return static_cast<float>(B) / INTCOLOR_MAX;
}

float util::Color::getAlphaF() const {
	return static_cast<float>(A) / INTCOLOR_MAX;
}

void util::Color::setup(int red, int green, int blue, int alpha){
	R = red;
	G = green;
	B = blue;
	A = alpha;

}

void util::Color::setFromFloat(float red, float green, float blue, float alpha){
	R = static_cast<int>(red)	* INTCOLOR_MAX;
	G = static_cast<int>(green)	* INTCOLOR_MAX;
	B = static_cast<int>(blue)	* INTCOLOR_MAX;
	A = static_cast<int>(alpha)	* INTCOLOR_MAX;
}


















