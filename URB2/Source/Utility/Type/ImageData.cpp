#include "ImageData.h"
#include <Source/Utility/DxLibUtility/DxLibImageLoader.h>
#include <Source/Framework/Define.h>

util::ImageData::ImageData(){
}

util::ImageData::ImageData(const std::string & imageName, const Vector2 & oneImageSize, int imageNum){
	image			= util::DxLibImageLoader::loadImageDiv(TEXTURE_DIR + imageName + ".png", oneImageSize, imageNum);
	normalMap		= util::DxLibImageLoader::loadImageDiv(TEXTURE_DIR + imageName + "_normal.png", oneImageSize, imageNum);
	reflectionMap	= util::DxLibImageLoader::loadImageDiv(TEXTURE_DIR + imageName + "_reflection.png", oneImageSize, imageNum);
	size			= oneImageSize;
	setup();
}

void util::ImageData::setVertex(const Vector2& position){
	for (int i = 0; i < 6; ++i) {
		vertex[i].pos	= VGet((i % 2)*size.getIntX() + position.getIntX(), (((i + 1) / 3) % 2)*size.getIntY() + position.getIntY(), 0);
	}
}

void util::ImageData::setup(){
	for (int i = 0; i < 6; ++i) {
		vertex[i].pos	= VGet((i % 2)*size.getIntX(), (((i + 1) / 3) % 2)*size.getIntY(), 0);
		vertex[i].rhw	= 1.f;
		vertex[i].dif	= GetColorU8(255, 255, 255, 255);
		vertex[i].spc	= GetColorU8(0, 0, 0, 0);
		vertex[i].u		= (float)(i % 2);
		vertex[i].su	= (float)(i % 2);
		vertex[i].v		= (float)(((i + 1) / 3) % 2);
		vertex[i].sv	= (float)(((i + 1) / 3) % 2);
	}
}


