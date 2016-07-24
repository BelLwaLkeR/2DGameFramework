#pragma once
#include <vector>
#include <map>
#include <Source/Utility/SmartPtr.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Device/Input/eInputCode.h>

/**
* @class		GamePadAggregate
* @namespace	framework
* @brief		•¡”‚ÌƒQ[ƒ€ƒpƒbƒh‚ğ‚Ü‚Æ‚ß‚é
* @author		‘åX Œ’i
*/

namespace framework {
	class IInputDevice;
	class GamePad;
	class DxLibGamePad;
	class GamePadAggregate
	{
	public:
		GamePadAggregate();
		~GamePadAggregate();
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
