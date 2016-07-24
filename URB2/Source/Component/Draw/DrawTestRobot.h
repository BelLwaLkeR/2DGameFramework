#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawTestRobot
* @namespace	component
* @brief		アルファマップ・リフレクトマップが適応されたロボットを描画する。テスト用
* @author		大森 健司
*/


namespace component {
	class DrawTestRobot: public framework::DrawComponent{
	public:
		DrawTestRobot();
		~DrawTestRobot();
		void draw() override;
	private:

	};
}