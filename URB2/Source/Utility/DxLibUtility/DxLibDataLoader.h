#pragma once
#include <string>
#include <Source/Utility/Type/ImageData.h>

namespace util {
	class DxLibDataLoader
	{
	public:
		DxLibDataLoader()	{}
		~DxLibDataLoader()	{}

		static ImageData			loadImageData(const std::string& imageFilePath, const std::string& pixelShaderPath);
		static image_t				loadImageData(const std::string& imageFilePath);
		static pshader_t			loadPixelShaderData(const std::string& pshaderFilePath);
	};
}
