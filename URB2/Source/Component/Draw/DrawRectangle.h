#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawRectangle
* @namespace	component
* @brief		�l�p��`�悷��R���|�[�l���g�B�e�X�g�p
* @author		��X ���i
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
