#pragma once
#include <Source/Framework/Component/DrawComponent.h>

/**
* @class		DrawTestRobot
* @namespace	component
* @brief		�A���t�@�}�b�v�E���t���N�g�}�b�v���K�����ꂽ���{�b�g��`�悷��B�e�X�g�p
* @author		��X ���i
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