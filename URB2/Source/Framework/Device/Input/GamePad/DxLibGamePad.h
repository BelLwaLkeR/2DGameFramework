#pragma once
#include <map>
#include <Source/Framework/Device/Input/eInputCode.h>

/**
* @class		DxLibGamePad
* @namespace	framework
* @brief		DxLib�̃Q�[���p�b�h���͗p���b�p�N���X
* @author		��X ���i
*/


namespace framework {
	class DxLibGamePad
	{
	public:
		DxLibGamePad();
		~DxLibGamePad();
		bool isKeyDown(int padNo, eInputCode code);

	private:
	};
}