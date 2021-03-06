#pragma once
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>

/**
* @class		ImageRenderer
* @namespace	framework
* @brief		DxLibImageRendererを直接使わないようにした仲介クラス
* @author		大森 健司
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
