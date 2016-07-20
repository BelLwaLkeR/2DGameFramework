#pragma once
#include <Source/Framework/Component/DrawComponent.h>

namespace component {
	class DrawTestRobot: public framework::DrawComponent{
	public:
		DrawTestRobot();
		~DrawTestRobot();
		void draw() override;
	private:

	};
}