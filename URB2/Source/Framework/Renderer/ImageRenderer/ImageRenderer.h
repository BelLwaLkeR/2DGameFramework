#pragma once
#include <Source/Framework/Renderer/ImageRenderer/DxLibImageRenderer.h>


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
