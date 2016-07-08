#include "InputManager.h"
#include <Source/Framework/Device/Input/Keyboard/Keyboard.h>
#include <Source/Utility/SmartPtr.h>
framework::InputManager::InputManager(){
	m_pInputDeviceList.emplace_back(util::makeShared<Keyboard>());
}

framework::InputManager::~InputManager()
{
}

void framework::InputManager::update(){
	for (const auto& input : m_pInputDeviceList) {
		input->update();
	}
}

bool framework::InputManager::isKeyDown(eInputCode inputCode){
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyDown(inputCode)) { return true; }
	}
	return false;
}

bool framework::InputManager::isKeyUp(eInputCode inputCode) {
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyUp(inputCode)) { return true; }
	}
	return false;
}

bool framework::InputManager::isKeyPush(eInputCode inputCode){
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyPush(inputCode)) { return true; }
	}
	return false;
}

bool framework::InputManager::isKeyRelease(eInputCode inputCode){
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyRelease(inputCode)) { return true; }
	}
	return false;
}
