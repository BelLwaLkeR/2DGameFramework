#include "InputManager.h"
#include <Source/Framework/Device/Input/Keyboard/Keyboard.h>
#include <Source/Utility/SmartPtr.h>
framework::InputManager::InputManager() {
	m_pInputDeviceList.emplace_back(util::makeShared<Keyboard>());
	m_GamePadManager.joinGamePadList(&m_pInputDeviceList);

}

framework::InputManager::~InputManager()
{
}

void framework::InputManager::update(){
	for (const auto& input : m_pInputDeviceList) {
		input->update();
	}
}

std::bitset<INPUT_NUM> framework::InputManager::isKeyDown(eInputCode inputCode){
	std::bitset<INPUT_NUM> inputBit(0);
	int counter = 0;
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyDown(inputCode)) { inputBit.set(counter); }
		++counter;
	}
	return inputBit;
}

std::bitset<INPUT_NUM> framework::InputManager::isKeyUp(eInputCode inputCode) {
	std::bitset<INPUT_NUM> inputBit(0);
	int counter = 0;
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyUp(inputCode)) { inputBit.set(counter); }
		++counter;
	}
	return inputBit;
}

std::bitset<INPUT_NUM> framework::InputManager::isKeyPush(eInputCode inputCode){
	std::bitset<INPUT_NUM> inputBit(0);
	int counter = 0;
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyPush(inputCode)) { inputBit.set(counter); }
		++counter;
	}
	return inputBit;
}

std::bitset<INPUT_NUM> framework::InputManager::isKeyRelease(eInputCode inputCode){
	std::bitset<INPUT_NUM> inputBit(0);
	int counter = 0;
	for (const auto& input : m_pInputDeviceList) {
		if (input->isKeyRelease(inputCode)) { inputBit.set(counter); }
		++counter;
	}
	return inputBit;
}

bool framework::InputManager::isKeyDown(eInputDeviceCode device, eInputCode inputCode){
	return (isKeyDown(inputCode) & std::bitset<INPUT_NUM>(std::pow(2, (int)inputCode))).any();
}

bool framework::InputManager::isKeyUp(eInputDeviceCode device, eInputCode inputCode){
	return (isKeyUp(inputCode) & std::bitset<INPUT_NUM>(std::pow(2, (int)inputCode))).any();

}

bool framework::InputManager::isKeyPush(eInputDeviceCode device, eInputCode inputCode){
	return (isKeyPush(inputCode) & std::bitset<INPUT_NUM>(std::pow(2, (int)inputCode))).any();
}

bool framework::InputManager::isKeyRelease(eInputDeviceCode device, eInputCode inputCode){
	return (isKeyRelease(inputCode) & std::bitset<INPUT_NUM>(std::pow(2, (int)inputCode))).any();
}

bool framework::InputManager::isKeyDownAny(eInputCode inputCode){
	return isKeyDown(inputCode).any();
}

bool framework::InputManager::isKeyUpAny(eInputCode inputCode){
	return isKeyUp(inputCode).any();
}

bool framework::InputManager::isKeyPushAny(eInputCode inputCode){
	return isKeyPush(inputCode).any();
}

bool framework::InputManager::isKeyReleaseAny(eInputCode inputCode){
	return isKeyRelease(inputCode).any();
}
