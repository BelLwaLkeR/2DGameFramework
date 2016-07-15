#pragma once

#include <bitset>
#include <map>
#include <Source/Framework/Device/Input/GamePad/DxLibGamePad.h>
#include <Source/Framework/Device/Input/IInputDevice.h>


namespace framework {
	class GamePad: public IInputDevice
	{
	public:
		GamePad();
		GamePad(int padNo);
		~GamePad();
		void update()							override;
		bool isKeyDown(eInputCode inputCode)	override;
		bool isKeyUp(eInputCode inputCode)		override;
		bool isKeyPush(eInputCode inputCode)	override;
		bool isKeyRelease(eInputCode inputCode) override;

	private:
		std::map<eInputCode, eGamePadCode> m_ButtonMap;
		DxLibGamePad m_DxLibKeyboard;
		std::bitset<(int)eInputCode::_END_> m_PreButtonState;
		std::bitset<(int)eInputCode::_END_> m_CurButtonState;
		
		void updateCurButtonState();
		bool isDownCurState(eInputCode inputCode);
		bool isDownPreState(eInputCode inputCode);


	};
}