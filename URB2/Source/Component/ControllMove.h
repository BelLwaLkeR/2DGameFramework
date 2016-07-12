#pragma once
#include <Source/Framework/Component/UpdateComponent.h>

namespace component {
	class ControllMove: public framework::UpdateComponent
	{
	public:
		ControllMove();
		~ControllMove();
		virtual void update() override;

	private:
		float speed;

		void move();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();


	};
}
