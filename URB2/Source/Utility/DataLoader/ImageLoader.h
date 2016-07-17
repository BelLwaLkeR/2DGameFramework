#pragma once
#include <string>
#include <Source/Utility/DxLibUtility/DxLibImageLoader.h>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/Type/Vector2.h>

namespace util {
	class ImageLoader{
	public:
		ImageLoader()	{}
		~ImageLoader()	{}
		
		static util::ImageData loadImageData(const std::string& imageFilePath, const std::string& normalMapFilePath, const std::string& reflectionMapFilePath, const Vector2& oneImageSize, int imageNum);

	};
}