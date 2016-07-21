#pragma once

namespace util {
	struct Color{
		int R;
		int G;
		int B;
		int A;

		float getRedF()		const;
		float getGreenF()	const;
		float getBlueF()	const;
		float getAlphaF()	const;

		void setup(int red, int green, int blue, int alpha = 255);
		void setFromFloat(float red, float green, float blue, float alpha = 1.f);
	};
}