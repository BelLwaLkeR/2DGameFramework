#pragma once
#include <array>
#include <DxLib.h>
#include <Source/Utility/Type/Vector2.h>

/**
* @file			DxLibImageTypeName.h
* @namespace	util
* @brief		DxLibが使う形式を独自の名前にラッピング
* @author		大森 健司
*/

namespace util {
	using image_t	= int;
	using pshader_t	= int;
	using vertex_t	= VERTEX2DSHADER;
	using screen_t	= int;
}

