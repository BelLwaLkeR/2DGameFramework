#include "DxLibPixelShaderLoader.h"
#include <cassert>

util::pshader_t util::DxLibPixelShaderLoader::loadPixelShader(const std::string & pixelShaderFilePath){
	pshader_t handle = LoadPixelShader(pixelShaderFilePath.c_str());
	assert(handle > -1 && "�s�N�Z���V�F�[�_�̓ǂݍ��݂Ɏ��s���܂����B");
	return handle;
}
