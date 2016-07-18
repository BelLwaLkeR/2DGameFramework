#include "DxLibImageLoader.h"
#include <Source/Framework/Define.h>
#include <cassert>
std::vector<util::image_t> util::DxLibImageLoader::loadImageDiv(const std::string & filePath, const Vector2 & oneImageSize, int imageNum){
	std::vector<util::image_t> imageHandle(imageNum);
	LoadDivGraph(filePath.c_str(), imageNum, imageNum, 1, oneImageSize.getIntX(), oneImageSize.getIntY(), &imageHandle[0]);
#ifdef DEBUG_MODE
	bool isError = false;
	for (const auto& image : imageHandle) {
		if (image < 0) { isError = true; }
	}
	assert(!isError && "‰æ‘œ‚Ì“Ç‚Ýž‚Ý‚ÉŽ¸”s‚µ‚Ü‚µ‚½B");
#endif
	return imageHandle;
}
