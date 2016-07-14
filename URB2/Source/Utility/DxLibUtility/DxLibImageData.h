#pragma once

#include <Source/Utility/Type/Vector2.h>

namespace util {
	using image_t	= int;
	using pshader_t	= int;


	struct DxLibImageData{
		image_t		image;
		pshader_t	shader;
	};
}

