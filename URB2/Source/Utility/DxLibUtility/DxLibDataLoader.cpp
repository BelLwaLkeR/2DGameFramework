#include "DxLibDataLoader.h"
#include <DxLib.h>

util::ImageData util::DxLibDataLoader::loadImageData(const std::string& imageFilePath, const std::string& pixelShaderPath){
	image_t&& imageDataHandle		= LoadGraph(imageFilePath.c_str());
	pshader_t&& shaderDataHandle	= LoadPixelShader(pixelShaderPath.c_str());
	return ImageData(imageDataHandle, shaderDataHandle);
}

util::AnimationImageData util::DxLibDataLoader::loadAnimationImageData(const std::string & imageFilePath, const std::string & pixelShaderPath, int oneImageWidth, int oneImageHeight, int numX, int numY){
	std::vector<image_t>	imageDataList(numX * numY);
	LoadDivGraph(imageFilePath.c_str(), numX * numY, numX, numY, oneImageWidth, oneImageHeight, &imageDataList[0]);
	return AnimationImageData(imageDataList, oneImageWidth, oneImageHeight, numX, numY);
}

util::image_t util::DxLibDataLoader::loadImageData(const std::string & imageFilePath){
	return LoadGraph(imageFilePath.c_str());
}

util::pshader_t util::DxLibDataLoader::loadPixelShaderData(const std::string & pshaderFilePath){
	return LoadPixelShader(pshaderFilePath.c_str());
}






