#pragma once
#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawTreasureBox
* @namespace	component
* @brief		アルファマップ・リフレクトマップが適応された宝箱を描画する。テスト用
* @author		大森 健司
*/


namespace component {
	class DrawTreasureBox : public framework::DrawComponent {
	public:
		DrawTreasureBox();
		~DrawTreasureBox();
		void draw() override;
	private:

	};
}