#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define DEBUG_MODE
#endif // DEBUG || _DEBUG

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



