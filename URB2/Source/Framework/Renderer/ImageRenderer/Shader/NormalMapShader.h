#pragma once
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/PixelShader.h>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Type/ImageData.h>


namespace framework {
	class NormalMapShader: public PixelShader
	{
	public:
		NormalMapShader();
		~NormalMapShader();

		void draw(const util::ImageData& image, const util::Vector2& position);

	private:


	};

}

