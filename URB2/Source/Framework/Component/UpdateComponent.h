#pragma once
#include <Source/Framework/Component/Component.h>

/**
* @class		UpdateComponent
* @inheritance	Component
* @namespace	framework
* @brief		Update�p�R���|�[�l���g�C���^�[�t�F�[�X
* @author		��X ���i
*/



namespace framework {
	class UpdateComponent : public Component{
	public:
		UpdateComponent();
		~UpdateComponent();

		virtual void update() = 0;
		void active();
		void deActive();

	};
}