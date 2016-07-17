#pragma once
#include <vector>
#include <Source/Utility/DxLibUtility/DxLibImageTypename.h>
#include <Source/Utility/DataLoader/ImageLoader.h>

namespace util {
	struct ImageData{
		ImageData();
		ImageData(const image_t& imageData, const pshader_t& shaderData, const Vector2& oneImageSize = {0, 0}, int imageNum = 0);
		void setVertex(const Vector2& position);
		Vector2							size;
		std::vector<image_t>			image;
		std::vector<image_t>			normalMap;
		std::vector<image_t>			reflectionMap;
		std::array<VERTEX2DSHADER, 6>	vertex;



	};
}