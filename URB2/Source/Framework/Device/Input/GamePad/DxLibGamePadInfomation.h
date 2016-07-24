#pragma once
#include <map>
#include <Source/Framework/Device/Input/GamePad/ePadButtonCode.h>

/**
* @class		DxLibGamePadInfomation
* @namespace	framework
* @brief		�Q�[���p�b�h�̃f�o�C�X�ƃ{�^���R�[�h���܂Ƃ߂��N���X
* @author		��X ���i
*/


namespace framework {
	class DxLibGamePadInfomation{
	public:
		DxLibGamePadInfomation() {}
		~DxLibGamePadInfomation() {}

	protected:
		static int getDeviceNo(int padNo);
		static int getPadButtonNo(ePadButtonCode code);

	private:
		static std::map<ePadButtonCode, int>	m_ButtonNumberMap;
	};
}



