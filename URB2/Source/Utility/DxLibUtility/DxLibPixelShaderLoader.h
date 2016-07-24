#pragma once

#include <string>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>

/**
* @class		DxLibShaderLoader
* @namespace	util
* @brief		DxLibの機能を用いて、Shaderの読み込み・削除を行う。
* @author		大森 健司
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
