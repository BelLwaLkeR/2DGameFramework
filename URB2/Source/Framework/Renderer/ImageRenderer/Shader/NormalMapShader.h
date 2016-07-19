#pragma once
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/PixelShader.h>
#include <Source/Utility/SmartPtr.h>

namespace util {
	class ImageData;
}

namespace framework {
	struct Light;
	class NormalMapShader: public PixelShader{
	public:
		NormalMapShader();
		~NormalMapShader();
		void changeImageData(util::WeakPtr<util::ImageData> pImageData);
		void draw();

	private:
		util::WeakPtr<util::ImageData> m_pImageData;
		void setup();
		void drawBegin();
		void drawEnd();
	};

}

