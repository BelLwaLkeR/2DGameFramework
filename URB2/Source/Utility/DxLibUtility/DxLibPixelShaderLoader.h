#pragma once

#include <string>
#include <DxLib.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>

namespace util {
	class DxLibPixelShaderLoader
	{
	public:
		DxLibPixelShaderLoader()	{}
		~DxLibPixelShaderLoader(){}
		static pshader_t loadPixelShader(const std::string& pixelShaderFilePath);


	private:

	};
}
