#pragma once
#include <Source/Framework/Device/Input/eInputCode.h>

/**
* @class		IInputDevice
* @namespace	framework
* @brief		���̓f�o�C�X�p�C���^�[�t�F�[�X
* @author		��X ���i
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



