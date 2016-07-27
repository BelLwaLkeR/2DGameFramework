#include "NormalMapShader.h"
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/DxLibShader.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>
#include <Source/Utility/Type/Color.h>
#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>

framework::NormalMapShader::NormalMapShader(){
	m_ShaderHandle = util::DxLibShaderLoader::loadPixelShader("NormalMapShader");
}

framework::NormalMapShader::~NormalMapShader(){

}

void framework::NormalMapShader::attachShader(util::SharedPtr<util::ImageData>* targetImage){
	util::WeakPtr<util::ImageData> pTargetImage = *targetImage;
	DxLibShaderFunction::setUsePixelShader(m_ShaderHandle);
	DxLibShaderFunction::setTexture(0, pTargetImage->getTexture());
	DxLibShaderFunction::setTexture(1, pTargetImage->getNormalMap());
	DxLibShaderFunction::setTexture(2, pTargetImage->getReflectionMap());

	const Light&			light						= *SGLT_LIGHT_AGGREGATE->getAffectLight((*targetImage)->getPosition()).front();
	const util::Color&		lightColor					= light.color;
	const util::Vector2&	lightPosition				= *(light.pPosition);
	const util::Vector2&	targetPosition				= pTargetImage->getPosition();
	float					lightPositionZ				= 10.f;
	std::vector<float>		relativeLightPosition		= { lightPosition.X - targetPosition.X, lightPosition.Y - targetPosition.Y, lightPositionZ };

	const util::Color&		ambientLight				= *SGLT_LIGHT_AGGREGATE->getAmbientLight();
	std::vector<float>		toShaderAmbientLightColor	= { ambientLight.getRedF()	, ambientLight.getGreenF()	, ambientLight.getBlueF() };
	std::vector<float>		toShaderLightColor			= { lightColor.getRedF()	, lightColor.getGreenF()	, lightColor.getBlueF() };

	DxLibShaderFunction::setValue		(0	, pTargetImage->getSize().X	);
	DxLibShaderFunction::setValue		(1	, pTargetImage->getSize().Y	);
	DxLibShaderFunction::setValueArray	(2	, toShaderAmbientLightColor	);
	DxLibShaderFunction::setValueArray	(5	, toShaderLightColor		);
	DxLibShaderFunction::setValueArray	(8	, relativeLightPosition		);
	DxLibShaderFunction::setValue		(11	, light.intencity);

	DxLibImageRenderer::drawImage(*pTargetImage);
}

void framework::NormalMapShader::deleteShader(){
	util::DxLibShaderLoader::deletePixelShader(m_ShaderHandle);
}
  