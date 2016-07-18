#include "ImageLoader.h"

util::ImageData util::ImageLoader::loadImageData(const std::string & imageFilePath, const std::string & normalMapFilePath, const std::string& reflectionMapFilePath, const Vector2 & oneImageSize, int imageNum){
	ImageData image;
	image.image			= DxLibImageLoader::loadImageDiv(imageFilePath			, oneImageSize, imageNum);
	image.normalMap		= DxLibImageLoader::loadImageDiv(normalMapFilePath		, oneImageSize, imageNum);
	image.reflectionMap	= DxLibImageLoader::loadImageDiv(reflectionMapFilePath	, oneImageSize, imageNum);
	image.size			= oneImageSize;
	return image;
}




