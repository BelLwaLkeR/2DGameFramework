#include "ShaderFactory.h"
#include <map>
#include <Source/Framework/Renderer/ImageRenderer/Shader/NormalMapShader.h>

framework::ShaderFactory::ShaderFactory(){

}

framework::ShaderFactory::~ShaderFactory(){

}

void framework::ShaderFactory::setupShaderMap(){
	m_pPixelShaderList["PixelShader"] = util::makeShared<NormalMapShader>();
}

util::WeakPtr<framework::PixelShader> framework::ShaderFactory::getPixelShader(const std::string& shaderTypeName){
	assert(	m_pPixelShaderList.find(shaderTypeName) != m_pPixelShaderList.end() &&
			"���݂��Ȃ��V�F�[�_���擾���悤�Ƃ��܂����B");
	return m_pPixelShaderList[shaderTypeName];
}
