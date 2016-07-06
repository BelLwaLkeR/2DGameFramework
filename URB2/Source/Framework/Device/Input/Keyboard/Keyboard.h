#pragma once

#include <bitset>
#include <map>
#include <Source/Framework/Device/Input/Keyboard/DxLibKeyboard.h>
#include <Source/Framework/Device/Input/IInputDevice.h>

namespace framework {
	class Keyboard: public IInputDevice{
	public:
		Keyboard();
		~Keyboard();
		
		void update()							override;
		bool isKeyDown(eInputCode inputCode)	override;
		bool isKeyUp(eInputCode inputCode)		override;
		bool isKeyPush(eInputCode inputCode)	override;
		bool isKeyRelease(eInputCode inputCode)	override;

	private:
		std::map<eInputCode, eKeyboardCode> m_KeyMap;
		DxLibKeyboard m_DxLibKeyboard;
		std::bitset<(int)eInputCode::_END_> m_PreKeyState;
		std::bitset<(int)eInputCode::_END_> m_CurKeyState;

		void updateCurKeyState();
		void setupKeyMap();
		bool isDownCurState(eInputCode inputCode);
		bool isDownPreState(eInputCode inputCode);
	};
}


