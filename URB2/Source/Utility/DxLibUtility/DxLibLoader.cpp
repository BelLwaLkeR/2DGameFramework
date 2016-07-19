#include "DxLibPixelShaderLoader.h"
#include <Source/Framework/Define.h>
#include <DxLib.h>
#include <cassert>

util::pshader_t util::DxLibShaderLoader::loadPixelShader(const std::string & shaderName){
	pshader_t handle = LoadPixelShader((SHADER_DIR + shaderName + SHADER_FOOTER).c_str());
	assert(handle >= 0 && "�V�F�[�_�̓ǂݍ��݂Ɏ��s���܂����B");
	return handle;
}

void util::DxLibShaderLoader::deletePixelShader(const pshader_t shaderHandle){
	DeleteShader(shaderHandle);

}
