#pragma once

#include <string>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>

/**
* @class		DxLibShaderLoader
* @namespace	util
* @brief		DxLib�̋@�\��p���āAShader�̓ǂݍ��݁E�폜���s���B
* @author		��X ���i
*/


namespace util {
	class DxLibShaderLoader{
	public:
		DxLibShaderLoader()	{}
		~DxLibShaderLoader(){}
		static pshader_t loadPixelShader(const std::string& shaderName);
		static void deletePixelShader(const pshader_t pixelShaderHandle);


	private:

	};
}
