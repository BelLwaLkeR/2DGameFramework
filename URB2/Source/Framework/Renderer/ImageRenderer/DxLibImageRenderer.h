#pragma once
#include <vector>
#include <DxLib.h>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/eDrawLayer.h>

namespace framework {
	class DxLibImageRenderer {
		void drawSimpleBox(const util::Vector2& centerPosition, int width, int height, float angleDeg);
		void beginRendaring();
		void endRendaring();
		void drawShader(const util::ImageData& image, const util::Vector2& position, eDrawLayer layer, const util::pshader_t& pixelShader, const std::vector<int>& param);
		void drawImage(const util::ImageData& image, const util::Vector2& position, eDrawLayer layer);

	};


}