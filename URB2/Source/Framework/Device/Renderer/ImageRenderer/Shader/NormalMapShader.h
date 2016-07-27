#pragma once
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/IPixelShader.h>
#include <Source/Utility/SmartPtr.h>

/**
* @class		NormalMapShader
* @inheritance	IPixelShader
* @namespace	framework
* @brief		ノーマルマップシェーダクラス
* @author		大森 健司
*/

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
		virtual void deleteShader() override;

	private:
		util::pshader_t m_ShaderHandle;



	};

}

