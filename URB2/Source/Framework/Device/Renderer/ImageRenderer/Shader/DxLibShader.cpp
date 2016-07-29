#include "DxLibShader.h"

#include <DxLib.h>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>
#include <Source/Utility/Type/Color.h>
#include <Source/Utility/Type/Vector3.h>
#include <Source/Utility/DxLibUtility/DxLibConverter.h>



framework::DxLibShaderFunction::DxLibShaderFunction(){

}

framework::DxLibShaderFunction::~DxLibShaderFunction(){

}

void framework::DxLibShaderFunction::setUsePixelShader(const util::pshader_t & pshader){
	SetUsePixelShader(pshader);
}

void framework::DxLibShaderFunction::setTexture(int valueIndex, const util::image_t & textureHandle){
	SetUseTextureToShader(valueIndex, textureHandle);
}

void framework::DxLibShaderFunction::setTexture(int valueIndex, const util::ImageData& imageData){
	setTexture(valueIndex, imageData.getTexture());
}

void framework::DxLibShaderFunction::setValue(int valueIndex, float value){
	SetPSConstSF(valueIndex, value);
}

void framework::DxLibShaderFunction::setValue(int valueIndex, const util::Vector2 & value){
	SetPSConstF(valueIndex, util::DxLibConverter::convertToFLOAT4(value));
}

void framework::DxLibShaderFunction::setValue(int valueIndex, const util::Vector3 & value){
	SetPSConstF(valueIndex, util::DxLibConverter::convertToFLOAT4(value));
}

void framework::DxLibShaderFunction::setValue(int valueIndex, const util::Color& value){
	SetPSConstF(valueIndex, util::DxLibConverter::convertToFLOAT4(value));
}

void framework::DxLibShaderFunction::setValueArray(int valueIndex, std::vector<float> valueList){
	int indexNum = valueList.size();
	if (indexNum <= 0) { return; }
	SetPSConstSFArray(valueIndex, &valueList[0], indexNum);
}

void framework::DxLibShaderFunction::setLightColor(int valueIndex, const util::Vector2& imagePosition){
	std::list<util::WeakPtr<framework::Light>> pLightList = SGLT_LIGHT_AGGREGATE->getAffectLight(imagePosition);
	if (pLightList.size() > 0) {
		setValue(valueIndex, pLightList.front()->color);
	}else{
		setValue(valueIndex, util::Color());
	}
}

void framework::DxLibShaderFunction::setAmbientLight(int valueIndex){
	setValue(valueIndex, *SGLT_LIGHT_AGGREGATE->getAmbientLight());
}

void framework::DxLibShaderFunction::setRelativePosition(int valueIndex, const util::ImageData & imageData, util::Vector2 & targetPosition){
	setRelativePosition(valueIndex, imageData.getPosition(), targetPosition);
}

void framework::DxLibShaderFunction::setRelativePosition(int valueIndex, const util::Vector2 & imagePosition, util::Vector2 & targetPosition){
	setValue(valueIndex, targetPosition - imagePosition);
}
















