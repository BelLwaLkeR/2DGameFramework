#pragma once
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Renderer/ImageRenderer/eDrawLayer.h>

namespace framework {
	class DrawComponent: public Component
	{
	public:
		DrawComponent();
		DrawComponent(eDrawLayer layer);
		~DrawComponent();

		virtual void draw() = 0;
		eDrawLayer m_Layer;
		void active();
		void deActive();
	};

}