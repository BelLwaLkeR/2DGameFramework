
#pragma once
#include <vector>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Renderer/ImageRenderer/eDrawLayer.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/IPixelShader.h>

namespace framework {
	class DrawComponent: public Component
	{
	public:
		DrawComponent();
		DrawComponent(eDrawLayer layer);
		~DrawComponent();

		template<typename ShaderType>
		void setShader();

		void draw();
		eDrawLayer m_Layer;
		std::vector<util::SharedPtr<IPixelShader>> m_pPixelShaderList;
		void active();
		void deActive();
	};

	template<typename ShaderType>
	inline void DrawComponent::setShader(){
		util::SharedPtr<IPixelShader> pshader = util::makeShared<ShaderType>();
		pshader->;
		m_pPixelShaderList.emplace_back(pshader);
	}
}