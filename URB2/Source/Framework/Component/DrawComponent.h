#pragma once
#include <Source/Framework/Component/Component.h>

namespace framework {
	class DrawComponent: public Component
	{
	public:
		DrawComponent();
		~DrawComponent();

		virtual void draw() = 0;
		void active();
		void deActive();
	};

}