#pragma once
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/IPixelShader.h>
#include <Source/Utility/SmartPtr.h>

namespace util {
	class ImageData;
}

namespace framework {
	struct Light;
	class NormalMapShader: public IPixelShader{
	public:
		NormalMapShader();
		~NormalMapShader();
		void changeImageData(util::WeakPtr<util::ImageData> pImageData);
		virtual void attachShader(util::SharedPtr<util::ImageData>* targetImage) override;

	private:
		util::WeakPtr<util::ImageData> m_pImageData;
		void setup();
		void drawBegin();
		void drawEnd();
	};

}

