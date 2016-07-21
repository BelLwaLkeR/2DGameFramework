#pragma once

#include <vector>
#include <memory>
#include <bitset>
#include <Source/Framework/Define.h>
#include <Source/Framework/Device/Input/eInputCode.h>
#include <Source/Framework/Device/Input/eInputDeviceCode.h>
#include <Source/Framework/Device/Input/GamePad/GamePadAggregate.h>
#include <Source/Utility/Singleton.h>

#define SGLT_INPUT_MANAGER framework::InputManager::getInstance()

namespace framework {
	class IInputDevice;
	class InputManager: public util::Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

		void update();
		std::bitset<INPUT_NUM> isKeyDown(eInputCode inputCode);
		std::bitset<INPUT_NUM> isKeyUp(eInputCode inputCode);
		std::bitset<INPUT_NUM> isKeyPush(eInputCode inputCode);
		std::bitset<INPUT_NUM> isKeyRelease(eInputCode inputCode);

		bool isKeyDown(eInputDeviceCode device, eInputCode inputCode);
		bool isKeyUp(eInputDeviceCode device, eInputCode inputCode);
		bool isKeyPush(eInputDeviceCode device, eInputCode inputCode);
		bool isKeyRelease(eInputDeviceCode device, eInputCode inputCode);

		bool isKeyDownAny(eInputCode inputCode);
		bool isKeyUpAny(eInputCode inputCode);
		bool isKeyPushAny(eInputCode inputCode);
		bool isKeyReleaseAny(eInputCode inputCode);

	private:
		std::vector<util::SharedPtr<IInputDevice>>	m_pInputDeviceList;
		GamePadAggregate							m_GamePadManager;
		bool isKeyDownKeyboard();
		bool isKeyDownGamePad();
		

	};

}




