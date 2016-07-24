#pragma once
#include <Source/Framework/Component/Component.h>

/**
* @class		UpdateComponent
* @inheritance	Component
* @namespace	framework
* @brief		Update用コンポーネントインターフェース
* @author		大森 健司
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