#include "Math.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cassert>

const float util::Math::PI = M_PI;

int util::Math::clamp(int value, int max, int min){
	swapMinMax(&min, &max);
	return static_cast<int>(std::fmin(std::fmaxf(value, min), max));
}

int util::Math::loop(int value, int max, int min){
	int distance = max - min;
	value -= min;
	value %= distance;
	value += min;
	return value;

}


