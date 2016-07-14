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
	swapMinMax(&min, &max);
	int distance = max - min;
	if (value >= min) {
		value -= min;
		value %= distance;
		value += min;
		return value;
	} else {
		assert(!"min–¢–‚Ìvalue‚É‘Î‚·‚éloop‚Í–¢À‘•‚Å‚·B");
		//¡TODO À‘•‚¹‚æ
	}

}

void util::Math::swap(int * value1, int * value2){
	swap<int>(value1, value2);
}

void util::Math::swapMinMax(int * min, int * max){
	swapMinMax<int>(min, max);
}






