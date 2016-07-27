#pragma once
#include <Source/Framework/Device/Renderer/ImageRenderer/DxLibImageRenderer.h>

/**
* @class		ImageRenderer
* @namespace	framework
* @brief		DxLibImageRenderer�𒼐ڎg��Ȃ��悤�ɂ�������N���X
* @author		��X ���i
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
