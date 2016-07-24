#pragma once
#include <Source/Framework/Component/UpdateComponent.h>

/**
* @class		ControllMove
* @namespace	component
* @brief		上下左右キーで、エンティティを移動させる。
* @author		大森 健司
*/


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
