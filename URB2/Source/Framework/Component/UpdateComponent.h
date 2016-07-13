#pragma once
#include <Source/Framework/Component/Component.h>

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