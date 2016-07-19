#include "NormalMapShader.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>

framework::NormalMapShader::NormalMapShader(){
	PixelShader("NormalMapShader");
}

framework::NormalMapShader::~NormalMapShader(){

}

void framework::NormalMapShader::changeImageData(util::WeakPtr<util::ImageData> pImageData){
	m_pImageData = pImageData;
}

void framework::NormalMapShader::draw(){
	drawBegin();
	framework::DxLibImageRenderer::drawImage(m_pImageData);
	drawEnd();
}

void framework::NormalMapShader::setup(){

}

void framework::NormalMapShader::drawBegin(){
	PixelShader::loadShader();
}

void framework::NormalMapShader::drawEnd(){
	PixelShader::deleteShader();
}
  