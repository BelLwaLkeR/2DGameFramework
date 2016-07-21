#include "NormalMapShader.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/DxLibShader.h>
#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>

framework::NormalMapShader::NormalMapShader(){

}

framework::NormalMapShader::~NormalMapShader(){

}

void framework::NormalMapShader::attachShader(util::SharedPtr<util::ImageData>* targetImage){
	util::pshader_t shaderHandle = util::DxLibShaderLoader::loadPixelShader("NormalMapShader");
	DxLibShaderFunction::setUsePixelShader(shaderHandle);
	DxLibShaderFunction::setTexture(0, (*targetImage)->getTexture());
	DxLibShaderFunction::setTexture(1, (*targetImage)->getNormalMap());
	DxLibShaderFunction::setTexture(2, (*targetImage)->getReflectionMap());


//	std::array<float, 3> relativeLightPosition = { 100 - m_pImageData->getPosition().X, 100 - m_pImageData->getPosition().Y, 0 };
	std::vector<float> relativeLightPosition = { 100 - (*targetImage)->getPosition().X, 100 - (*targetImage)->getPosition().Y, 0 };
	std::array<float, 3> ambientLightColor = { 0.3f, 0.2f, 0.2f };
	std::array<float, 3> LightColor = { 1.f, 1.f, 1.f };


	DxLibShaderFunction::setValue(0, (*targetImage)->getSize());
	DxLibShaderFunction::setAmbientLight(2);
	DxLibShaderFunction::setLightColor(5, (*targetImage)->getPosition());
	DxLibShaderFunction::setValueArray(8, relativeLightPosition);
	DxLibShaderFunction::setValue(11, 5);

	util::DxLibShaderLoader::deletePixelShader(shaderHandle);
}
  