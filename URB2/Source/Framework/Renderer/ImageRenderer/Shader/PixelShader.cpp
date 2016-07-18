#include "PixelShader.h"
#include <cassert>
#include <Source/Utility/DxLibUtility/DxLibPixelShaderLoader.h>


framework::PixelShader::PixelShader(){
	m_ShaderHandle = -1;
}

framework::PixelShader::PixelShader(const std::string & filePath){
	load(filePath);
}

framework::PixelShader::~PixelShader(){
	
}

void framework::PixelShader::load(const std::string & filePath){
	m_ShaderHandle = util::DxLibPixelShaderLoader::loadPixelShader(filePath);
}

util::pshader_t framework::PixelShader::get(){
	assert(m_ShaderHandle > -1 && "�ǂݍ��݂�����Ă��Ȃ��A�������͎��s���Ă���V�F�[�_���擾���悤�Ƃ��܂����B");
	return m_ShaderHandle;
}
