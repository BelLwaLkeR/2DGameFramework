#pragma once
#include <vector>
#include <string>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/DataLoader.h>

namespace util {
	struct AnimationImageData{
		std::vector<image_t>	imageList;

		int oneImageWidth;
		int oneImageHeight;
		int imageNumX;
		int imageNumY;

		AnimationImageData() {}
		AnimationImageData(const std::vector<image_t>& imageList, int oneImageWidth, int oneImageHeight, int numX, int numY) {
			this->imageList			= imageList;
			this->oneImageWidth		= oneImageWidth;
			this->oneImageHeight	= oneImageHeight;
			this->imageNumX			= numX;
			this->imageNumY			= numY;
		}

	};
}