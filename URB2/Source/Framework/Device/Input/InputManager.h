#pragma once

#include <vector>
#include <memory>
#include <Source/Framework/Device/Input/eInputCode.h>
#include <Source/Utility/Singleton.h>

#define SGLT_INPUTMANAGER framework::InputManager::getInstance()

namespace framework {
	class IInputDevice;
	class InputManager: public util::Singleton<InputManager>
	{
	public:
		InputManager();
		~InputManager();

		void update();
		bool isKeyDown(eInputCode inputCode);
		bool isKeyUp(eInputCode inputCode);
		bool isKeyPush(eInputCode inputCode);
		bool isKeyRelease(eInputCode inputCode);

	private:
		std::vector<std::shared_ptr<IInputDevice>> m_pInputDeviceList;
		

	};

}




