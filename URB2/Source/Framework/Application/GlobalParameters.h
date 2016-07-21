#pragma once

#include <chrono>
#include <Source/Utility/Singleton.h>

namespace framework {
	class GlobalParameters: public util::Singleton<GlobalParameters>
	{
	public:
		GlobalParameters();
		~GlobalParameters();
		void update();
		const unsigned long& getGameCount();

	private:
		unsigned long	m_GameCounter;
	};
}