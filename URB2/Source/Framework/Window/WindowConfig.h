#pragma once

#include <string>

/**
* @struct		WindowConfig
* @namespace	framework
* @brief		Window生成用の設定をまとめた構造体
* @author		大森 健司
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