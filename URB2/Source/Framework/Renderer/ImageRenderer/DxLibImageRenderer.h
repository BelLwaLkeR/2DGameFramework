#pragma once
#include <vector>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Type/ImageData.h>

namespace util {
	struct Vector2;
}

namespace framework {
	class DxLibImageRenderer {
	public:
		static void drawSimpleBox(const util::Vector2& centerPosition, int width, int height, float angleDeg);
		static void drawImage(util::WeakPtr<util::ImageData> pIimageData);

	};


}