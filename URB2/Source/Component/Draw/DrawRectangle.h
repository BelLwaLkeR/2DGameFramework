#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawRectangle
* @namespace	component
* @brief		四角を描画するコンポーネント。テスト用
* @author		大森 健司
*/



namespace component {
	class DrawRectangle: public framework::DrawComponent
	{
	public:
		DrawRectangle();
		~DrawRectangle();
		void draw() override;
	private:

	};
}
