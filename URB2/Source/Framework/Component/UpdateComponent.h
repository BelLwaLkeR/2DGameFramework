#pragma once
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Task/IUpdateTask.h>

namespace framework {
	class UpdateComponent : public Component, IUpdateTask
	{
	public:
		UpdateComponent() {}
		~UpdateComponent() {}
	private:

	};
}