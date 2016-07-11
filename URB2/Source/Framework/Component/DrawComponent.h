#pragma once
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Task/IDrawTask.h>


namespace framework {
	class DrawComponent: public Component, IDrawTask
	{
	public:
		DrawComponent()	{}
		~DrawComponent() {}

	private:
	};

}