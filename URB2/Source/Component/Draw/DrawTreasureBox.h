#pragma once
#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawTreasureBox
* @namespace	component
* @brief		�A���t�@�}�b�v�E���t���N�g�}�b�v���K�����ꂽ�󔠂�`�悷��B�e�X�g�p
* @author		��X ���i
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