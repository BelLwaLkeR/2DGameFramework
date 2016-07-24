#pragma once
#include <vector>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/Type/Vector2.h>

/**
* @class		DxLibImageRenderer
* @namespace	framework
* @brief		DxLibを用いた描画関数のラッパクラス
* @author		大森 健司
*/

namespace util {
	struct Vector2;
}

namespace framework {
	class DxLibImageRenderer {
	public:
		static util::image_t makeScreen(const util::Vector2& size);
		static void drawSimpleBox(const util::Vector2& centerPosition, int width, int height, float angleDeg);
		static void drawImage(const util::ImageData& imageData);
		static void setDrawScreen(const util::screen_t& screen);
		static void drawScreen(const util::screen_t& screen, util::Vector2& position);
		static void drawScreenForWindow(const util::screen_t& screen);
		static void setScreenAplicationBack();
		static void standbyScreenApplicationBack();
		static void clearScreen();
		static void screenFlip();
	};


}