#pragma once
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>

/**
* @class		ImageRenderer
* @namespace	framework
* @brief		DxLibImageRenderer‚ğ’¼Úg‚í‚È‚¢‚æ‚¤‚É‚µ‚½’‡‰îƒNƒ‰ƒX
* @author		‘åX Œ’i
*/


namespace util{
	class ImageData;
}
namespace framework {
	class ImageRenderer{
	public:
		ImageRenderer();
		~ImageRenderer();

		static void drawImage(util::WeakPtr<util::ImageData> pImage);



	private:

	};
}
