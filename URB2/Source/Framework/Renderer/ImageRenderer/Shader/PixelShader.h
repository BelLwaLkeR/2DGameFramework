#pragma once
#include <string>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>


namespace framework {
	class  PixelShader
	{
	public:
		PixelShader();
		PixelShader(const std::string& filePath);
		~PixelShader();
		void load(const std::string& filePath);
		util::pshader_t get();

	private:
		util::pshader_t m_ShaderHandle;
	};
}