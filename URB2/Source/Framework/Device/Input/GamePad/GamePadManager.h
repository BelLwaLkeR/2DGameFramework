#pragma once
#include <array>
#include <map>
#include <Source/Framework/Device/Input/GamePad/GamePad.h>
#include <Source/Utility/SmartPtr.h>

namespace framework {
	class GamePadManager
	{
	public:
		GamePadManager();
		~GamePadManager();

		void addGamePad(int padNo);
		util::WeakPtr<GamePad> getGamePad(int padNo);

	private:
		std::array<util::SharedPtr<GamePad>, 3> m_pGamePadList;
		std::map<int, int>						m_DeviceNoMap;

	};
}
