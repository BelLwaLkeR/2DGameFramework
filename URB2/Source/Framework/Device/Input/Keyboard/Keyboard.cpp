#include "Keyboard.h"

framework::Keyboard::Keyboard(){
	setupKeyMap();
}

framework::Keyboard::~Keyboard(){

}

void framework::Keyboard::update(){
	m_DxLibKeyboard.updateKeyStateBuffer();
	m_PreKeyState = m_CurKeyState;
	updateCurKeyState();
}

bool framework::Keyboard::isKeyDown(eInputCode inputCode){
	return isDownCurState(inputCode);
}

bool framework::Keyboard::isKeyUp(eInputCode inputCode){
	return !isDownCurState(inputCode);
}

bool framework::Keyboard::isKeyPush(eInputCode inputCode){
	return isDownCurState(inputCode) && !isDownPreState(inputCode);
}

bool framework::Keyboard::isKeyRelease(eInputCode inputCode){
	return !isDownCurState(inputCode) && isDownPreState(inputCode);
}

void framework::Keyboard::updateCurKeyState(){
	m_CurKeyState.reset();
	for (int i = 0; i < (int)eInputCode::_END_; ++i) {
		if (m_DxLibKeyboard.isKeyDown(m_KeyMap[(eInputCode)i])) {
			m_CurKeyState.set(i);
		}
	}
}

void framework::Keyboard::setupKeyMap(){
	m_KeyMap.clear();
	m_KeyMap[eInputCode::UP]		= eKeyboardCode::UP;
	m_KeyMap[eInputCode::DOWN]		= eKeyboardCode::DOWN;
	m_KeyMap[eInputCode::LEFT]		= eKeyboardCode::LEFT;
	m_KeyMap[eInputCode::RIGHT]		= eKeyboardCode::RIGHT;
	m_KeyMap[eInputCode::ATTACK]	= eKeyboardCode::Z;
	m_KeyMap[eInputCode::SKILL]		= eKeyboardCode::X;
	m_KeyMap[eInputCode::APEAL]		= eKeyboardCode::C;
	m_KeyMap[eInputCode::EXIT]		= eKeyboardCode::ESC;
}

bool framework::Keyboard::isDownCurState(eInputCode inputCode){
	return (m_CurKeyState & std::bitset<static_cast<int>(eInputCode::_END_)>(std::pow(2, (int)inputCode))).any();
}

bool framework::Keyboard::isDownPreState(eInputCode inputCode){
	return (m_PreKeyState & std::bitset<static_cast<int>(eInputCode::_END_)>(std::pow(2, (int)inputCode))).any();
}
