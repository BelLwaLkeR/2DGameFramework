#include "Color.h"

const int util::Color::maxValue = 255;

float util::Color::getRedF(){
	return static_cast<float>(r) / maxValue;
}

float util::Color::getGreenF(){
	return static_cast<float>(g) / maxValue;
}

float util::Color::getBlueF() {
	return static_cast<float>(b) / maxValue;
}

float util::Color::getAlphaF() {
	return static_cast<float>(a) / maxValue;
}

void util::Color::setup(int red, int green, int blue, int alpha){
	r = red;
	g = green;
	b = blue;
	a = alpha;

}

void util::Color::setFromFloat(float red, float green, float blue, float alpha){
	r = red		* maxValue;
	g = green	* maxValue;
	b = blue	* maxValue;
	a = alpha	* maxValue;
}


















