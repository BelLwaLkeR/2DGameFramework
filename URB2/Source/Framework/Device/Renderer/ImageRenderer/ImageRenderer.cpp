#include "ImageRenderer.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>

framework::ImageRenderer::ImageRenderer(){
}

framework::ImageRenderer::~ImageRenderer(){
}

void framework::ImageRenderer::drawImage(util::WeakPtr<util::ImageData> pImage){
	DxLibImageRenderer::drawImage(*pImage);
}
