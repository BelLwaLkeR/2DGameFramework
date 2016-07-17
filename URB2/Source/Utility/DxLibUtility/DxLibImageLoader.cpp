#include "DxLibImageLoader.h"

std::vector<util::image_t> util::DxLibImageLoader::loadImageDiv(const std::string & filePath, const Vector2 & oneImageSize, int imageNum){
	std::vector<util::image_t> imageHandle(imageNum);
	LoadDivGraph(filePath.c_str(), imageNum, imageNum, 1, oneImageSize.getIntX(), oneImageSize.getIntY(), &imageHandle[0]);
	return imageHandle;
}
