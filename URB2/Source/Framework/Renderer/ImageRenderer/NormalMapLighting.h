#pragma once

#include <vector>
#include <Source/Utility/Type/ImageData.h>
#include <Source/Framework/Renderer/ImageRenderer/Light.h>

namespace framework {
	class NormalMapLighting
	{
	public:
		NormalMapLighting();
		~NormalMapLighting();
		void setup();
		void draw(const util::image_t& texture, const util::image_t& normalmap, const std::vector<Light>& vectorList);


	private:
		util::pshader_t m_PixelShader;



	};
}