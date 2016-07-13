#pragma once
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Task/IDrawTask.h>


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