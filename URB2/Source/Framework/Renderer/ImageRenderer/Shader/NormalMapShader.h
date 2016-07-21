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
		virtual void attachShader(util::SharedPtr<util::ImageData>* targetImage) override;
	};

}

