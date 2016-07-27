#pragma once

#include <vector>
#include <Source/Utility/DxLibUtility/DxLibImageTypeName.h>

/**
* @class		DxLibShaderFunction
* @namespace	framework
* @brief		DxLibのシェーダ関係関数をまとめたクラス
* @author		大森 健司
*/

namespace util {
	struct Color;
	class ImageData;
}

namespace framework {
	using float4 = FLOAT4;
	using float3 = FLOAT3;

	class DxLibShaderFunction{
	public:
		DxLibShaderFunction();
		~DxLibShaderFunction();
		static void setUsePixelShader	(const util::pshader_t& pshader);

		static void setTexture			(int valueIndex, const util::image_t&	textureHandle	);
		static void setTexture			(int valueIndex, const util::ImageData&	imageData		);
		static void setValue			(int valueIndex, float value							);
		static void setValue			(int valueIndex, const util::Vector2&	value			);
		static void setValue			(int valueIndex, const util::Color&		value			);
		static void setValueArray		(int valueIndex, std::vector<float>		valueList		);
		static void setLightColor		(int valueIndex, const util::Vector2&	imagePosition	);
		static void setAmbientLight		(int valueIndex);
		static void setRelativePosition	(int valueIndex, const util::ImageData&	imageData		, util::Vector2& targetPosition);
		static void setRelativePosition	(int valueIndex, const util::Vector2&	imagePosition	, util::Vector2& targetPosition);



	private:
	};

}