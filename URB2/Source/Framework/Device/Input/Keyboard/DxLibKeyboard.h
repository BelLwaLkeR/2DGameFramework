#pragma once
#include <DxLib.h>
#include <map>
#include <Source/Framework/Device/Input/Keyboard/eKeyboardCode.h>

namespace framework {
	class DxLibKeyboard{
	public:
		DxLibKeyboard();
		~DxLibKeyboard();

		bool isKeyDown(eKeyboardCode keyCode);
	private:
		std::map<eKeyboardCode, int> eKeyCodeMap;
		void setupEKeyCodeMap();
};
}



