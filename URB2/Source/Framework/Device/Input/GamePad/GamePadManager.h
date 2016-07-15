#pragma once
#include <vector>
#include <map>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Device/Input/eInputCode.h>

namespace framework {
	class IInputDevice;
	class GamePad;
	class DxLibGamePad;
	class GamePadManager
	{
	public:
		GamePadManager();
		~GamePadManager();
		void setup();
		
		//void update();
		//bool isKeyDown(int padNo	, eInputCode inputCode);
		//bool isKeyUp(int padNo		, eInputCode inputCode);
		//bool isKeyPush(int padNo	, eInputCode inputCode);
		//bool isKeyRelease(int padNo	, eInputCode inputCode);
		void joinGamePadList(std::vector<util::SharedPtr<IInputDevice>>* inputList);


	private:
		std::vector<util::SharedPtr<GamePad>>	m_pGamePadList;
		util::SharedPtr<DxLibGamePad>			m_pDxLibGamePad;

		util::SharedPtr<GamePad> setupGamePad(int padNo);
		void assertFallPadNo(int padNo);


	};
}
