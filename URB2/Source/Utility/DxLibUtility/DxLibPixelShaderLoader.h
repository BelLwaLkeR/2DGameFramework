#pragma once

#include <string>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>

namespace util {
	class DxLibShaderLoader
	{
	public:
		DxLibShaderLoader()	{}
		~DxLibShaderLoader()	{}
		static pshader_t loadPixelShader(const std::string& shaderName);
		static void deletePixelShader(const pshader_t pixelShaderHandle);


	private:

	};
}
