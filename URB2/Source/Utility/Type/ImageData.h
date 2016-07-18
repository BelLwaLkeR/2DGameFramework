#pragma once
#include <vector>
#include <string>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypename.h>

namespace util {
	struct ImageData{
		ImageData();
		ImageData(const std::string& imageName, const Vector2& oneImageSize = {0, 0}, int imageNum = 0);
		void setVertex(const Vector2& position);
		void setup();
		Vector2					size;
		std::vector<image_t>	image;
		std::vector<image_t>	normalMap;
		std::vector<image_t>	reflectionMap;
		std::array<vertex_t, 6>	vertex;
	};
}