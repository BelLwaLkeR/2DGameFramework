#include "NormalMapShader.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>


framework::NormalMapShader::NormalMapShader(){

}

framework::NormalMapShader::~NormalMapShader(){

}

void framework::NormalMapShader::changeImageData(util::WeakPtr<util::ImageData> pImageData){
	m_pImageData = pImageData;
}

void framework::NormalMapShader::attachShader(util::SharedPtr<util::ImageData>* targetImage){
	util::pshader_t shaderHandle = util::DxLibShaderLoader::loadPixelShader("NormalMapShader");
	SetUsePixelShader(shaderHandle);
	SetUseTextureToShader(0, (*targetImage)->getTexture());
	SetUseTextureToShader(1, (*targetImage)->getNormalMap());
	SetUseTextureToShader(2, (*targetImage)->getReflectionMap());


	std::array<float, 3> relativeLightPosition = { 100, 100, 0};
	std::array<float, 3> ambientLightColor = { 0.5f, 0.5f, 0.5f };
	std::array<float, 3> LightColor = { 1.f, 1.f, 1.f };


	SetPSConstSF(0, (*targetImage)->getSize().getIntX());
	SetPSConstSF(1, (*targetImage)->getSize().getIntY());
	SetPSConstSFArray(2, &ambientLightColor[0], 3);
	SetPSConstSFArray(5, &LightColor[0], 3);
	SetPSConstSFArray(8, &relativeLightPosition[0], 3);
	SetPSConstSF(11, 5.f);

	util::DxLibShaderLoader::deletePixelShader(shaderHandle);
}

void framework::NormalMapShader::setup(){

}

void framework::NormalMapShader::drawBegin(){

}

void framework::NormalMapShader::drawEnd(){

}
  