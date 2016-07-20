#include "DxLibImageRenderer.h"
#include <DxLib.h>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Define.h>


util::image_t framework::DxLibImageRenderer::makeScreen(const util::Vector2 & size){
	return MakeScreen(size.getIntX(), size.getIntY(), TRUE);
}

void framework::DxLibImageRenderer::drawSimpleBox(const util::Vector2& centerPosition, int width, int height, float angleDeg){
	DrawBox(centerPosition.getIntX() - width/2,
			centerPosition.getIntX() + width/2,
			centerPosition.getIntX() - height/2,
			centerPosition.getIntX() + height/2,
			GetColor(0, 255, 128),
			TRUE
		);
}

void framework::DxLibImageRenderer::drawImage(const util::ImageData& imageData){
	DrawPolygon2DToShader(imageData.getVertexPointer(), 2);
}

void framework::DxLibImageRenderer::setDrawScreen(const util::screen_t & screen){
	SetDrawScreen(screen);
}

void framework::DxLibImageRenderer::drawScreen(const util::screen_t & screen, util::Vector2& position){
	DrawGraph(position.getIntX(), position.getIntY(), screen, TRUE);
}

void framework::DxLibImageRenderer::drawScreenForWindow(const util::screen_t & screen){
	DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, screen, TRUE);
}

void framework::DxLibImageRenderer::setScreenAplicationBack(){
	setDrawScreen(DX_SCREEN_BACK);
}

void framework::DxLibImageRenderer::standbyScreenApplicationBack(){
	setScreenAplicationBack();
	clearScreen();
}

void framework::DxLibImageRenderer::clearScreen(){
	ClearDrawScreen();
}









