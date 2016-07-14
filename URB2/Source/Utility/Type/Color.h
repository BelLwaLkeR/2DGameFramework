#pragma once

namespace util {
	struct Color{
		int r;
		int g;
		int b;
		int a;

		float getRedF();
		float getGreenF();
		float getBlueF();
		float getAlphaF();

		void setup(int red, int green, int blue, int alpha = 255);
		void setFromFloat(float red, float green, float blue, float alpha = 1.f);

	private:
		static const int maxValue;
	};
}