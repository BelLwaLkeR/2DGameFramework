#pragma once
#include <map>
#include <Source/Framework/Device/Input/eInputCode.h>
#include <Source/Framework/Device/Input/GamePad/ePadButtonCode.h>
#include <Source/Framework/Device/Input/GamePad/DxLibGamePadInfomation.h>

/**
* @class		GamePadInfomationMediator
* @inheritance	DxLibGamePadInfomation
* @namespace	framework
* @brief		DxLib—p‚ÌGamePadî•ñ‚ğ’¼Úg‚í‚È‚¢‚æ‚¤‚É’‡‰î‚·‚é
* @author		‘åX Œ’i
*/



namespace framework {
	class GamePadInfomationMediator: public DxLibGamePadInfomation{
	public:
		GamePadInfomationMediator();
		~GamePadInfomationMediator();

		static int getDeviceNo(int padNo);
		static int getPadButtonCode(eInputCode code);
	private:
		static std::map<eInputCode, ePadButtonCode> m_InputCodeMap;
	};
}