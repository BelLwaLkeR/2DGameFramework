#pragma once
#include <Source/Utility/DxLibUtility/DxLibImageData.h>

namespace util {
	struct ImageData: public DxLibImageData{
		ImageData();
		ImageData(const image_t& imageData, const pshader_t& shaderData);

	};
}