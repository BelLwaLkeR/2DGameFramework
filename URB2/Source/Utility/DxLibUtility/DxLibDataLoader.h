#pragma once
#include <string>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Utility/Type/AnimationImageData.h>

namespace util {
	class DxLibDataLoader
	{
	public:
		DxLibDataLoader()	{}
		~DxLibDataLoader()	{}

		static ImageData			loadImageData(const std::string& imageFilePath, const std::string& pixelShaderPath);
		static AnimationImageData	loadAnimationImageData(const std::string& imageFilePath, const std::string& pixelShaderPath, int oneImageWidth, int oneImageHeight, int numX, int numY);
		static image_t				loadImageData(const std::string& imageFilePath);
		static pshader_t			loadPixelShaderData(const std::string& pshaderFilePath);
	};
}
