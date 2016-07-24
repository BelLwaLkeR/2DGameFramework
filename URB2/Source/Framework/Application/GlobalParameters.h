#pragma once

#include <chrono>
#include <Source/Utility/Singleton.h>

/**
* @class		GameApplication
* @inheritance	Singleton<GlobalParameters>
* @namespace	framework
* @brief		ƒQ[ƒ€©g‚Ìó‘ÔŠÇ—B
* @author		‘åX Œ’i
*/

#define SGLT_GLOBAL_PARAMETERS framework::GlobalParameters().getInstance()

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