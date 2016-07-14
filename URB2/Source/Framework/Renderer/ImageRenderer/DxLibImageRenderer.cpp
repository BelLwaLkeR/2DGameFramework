#include "DxLibImageRenderer.h"

void framework::DxLibImageRenderer::drawSimpleBox(const util::Vector2 & centerPosition, int width, int height, float angleDeg){
	DrawBox(centerPosition.getIntX() - width/2,
			centerPosition.getIntX() + width/2,
			centerPosition.getIntX() - height/2,
			centerPosition.getIntX() + height/2,
			GetColor(0, 255, 128),
			TRUE
		);
}

void framework::DxLibImageRenderer::beginRendaring(){

}

void framework::DxLibImageRenderer::endRendaring(){

}

void framework::DxLibImageRenderer::drawShader(const util::ImageData & image, const util::Vector2 & position, eDrawLayer layer, const util::pshader_t & pixelShader, const std::vector<int>& param){
	
}

void framework::DxLibImageRenderer::drawImage(const util::ImageData & image, const util::Vector2 & position, eDrawLayer layer){

}






