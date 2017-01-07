#pragma once

/**
* @file			Define.h
* @brief		各定数をまとめたファイル
* @author		大森 健司
*/

#if defined(DEBUG) || defined(_DEBUG)
#define DEBUG_MODE
#endif // DEBUG || _DEBUG

#define WINDOW_TITLE			"2DGameFramework"
#define WINDOW_WIDTH			1280
#define WINDOW_HEIGHT			720
#define SCREEN_WIDTH			1280
#define SCREEN_HEIGHT			720

#define EMPTY_VALUE				-1
#define INTCOLOR_MAX			255

#define USE_KEYBOARD_NUM		1
#define USE_PAD_NUM				12
#define INPUT_NUM				USE_KEYBOARD_NUM + USE_PAD_NUM

#define IMAGEDATA_DIR			std::string("./Resource/Texture/")
#define TEXTURE_FOOTER			std::string("_texture.png")
#define NORMALMAP_FOOTER		std::string("_normal.png")
#define REFLECTIONMAP_FOOTER	std::string("_reflection.png")

#define SHADER_DIR				std::string("./Resource/Shader/")
#define SHADER_FOOTER			std::string(".pso")

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef unsigned __int64	uint64;

typedef signed char			int8;
typedef signed short		int16;
typedef signed int			int32;
typedef signed __int64		int64;

typedef float				float32;
typedef double				float64;