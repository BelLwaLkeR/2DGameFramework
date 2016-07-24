#pragma once

#include <string>

/**
* @struct		WindowConfig
* @namespace	framework
* @brief		Window�����p�̐ݒ���܂Ƃ߂��\����
* @author		��X ���i
*/

namespace framework {
	struct WindowConfig{
		std::string		title;
		unsigned int	width;
		unsigned int	height;
		unsigned int	colorBit;
		unsigned int	fps;
		bool			isFullScreen;
		bool			canChangeWindowSize;

		WindowConfig(const std::string& title,
					unsigned int	width,
					unsigned int	height,
					unsigned int	colorBit,
					unsigned int	fps,
					bool			isFullScreen,
					bool			canChangeWindowSize = false) :

					title				(title),
					width				(width),
					height				(height),
					colorBit			(colorBit),
					fps					(fps),
					isFullScreen		(isFullScreen),
					canChangeWindowSize	(canChangeWindowSize){
		}
	};
}