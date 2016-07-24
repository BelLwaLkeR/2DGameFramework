#pragma once
#include <Source/Framework/Device/Input/eInputCode.h>

/**
* @class		IInputDevice
* @namespace	framework
* @brief		入力デバイス用インターフェース
* @author		大森 健司
*/

namespace framework {
	class IInputDevice
	{
	public:
		IInputDevice() {}
		~IInputDevice() {}
		virtual void update() = 0;
		virtual bool isKeyDown(eInputCode inputCode)	= 0;
		virtual bool isKeyUp(eInputCode inputCode)		= 0;
		virtual bool isKeyPush(eInputCode inputCode)	= 0;
		virtual bool isKeyRelease(eInputCode inputCode)	= 0;
	};
}



