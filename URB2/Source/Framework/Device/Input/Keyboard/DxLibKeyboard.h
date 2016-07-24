#pragma once
#include <map>
#include <Source/Framework/Device/Input/Keyboard/eKeyboardCode.h>
#include <array>

/**
* @class		DxLibKeyboard
* @namespace	framework
* @brief		DxLib�̃L�[�{�[�h�֐������b�v�����N���X
* @author		��X ���i
*/

namespace framework {
	class DxLibKeyboard{
	public:
		DxLibKeyboard();
		~DxLibKeyboard();
		void updateKeyStateBuffer();
		bool isKeyDown(eKeyboardCode keyCode);

	private:
		std::array<char, 256> keyStateBuffer;
		std::map<eKeyboardCode, int> eKeyCodeMap;
		void setupEKeyCodeMap();
	};
}



