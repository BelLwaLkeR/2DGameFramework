#pragma once

#include <vector>
#include <memory>
#include <Source/Framework/Device/Input/eInputCode.h>

namespace framework {
	class IInputDevice;
	class InputManager
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




