#include "GamePad.h"
#include <cassert>

framework::GamePad::GamePad():GamePad(-1){
}

framework::GamePad::GamePad(int padNo){
	assert( padNo>=0 &&	"�Q�[���p�b�h�̃R���X�g���N�^�ɂ́A0�ȏ�̃p�b�h�ԍ�����͂��ĉ������B\n\
						�f�t�H���g�R���X�g���N�^���Ăяo���ꂽ�ꍇ���A����assert���o�͂��܂��B");
	m_DxLibKeyboard.setPadNo(padNo);
}

framework::GamePad::~GamePad(){
}

void framework::GamePad::update(){
	m_PreButtonState = m_CurButtonState;
	updateCurButtonState();
}

bool framework::GamePad::isKeyDown(eInputCode inputCode){
	return isDownCurState(inputCode);
}

bool framework::GamePad::isKeyUp(eInputCode inputCode){
	return !isDownCurState(inputCode);
}

bool framework::GamePad::isKeyPush(eInputCode inputCode){
	return !isDownPreState(inputCode) && isDownCurState(inputCode);
}

bool framework::GamePad::isKeyRelease(eInputCode inputCode){
	return isDownPreState(inputCode) && !isDownCurState(inputCode);
}

void framework::GamePad::updateCurButtonState(){

}

bool framework::GamePad::isDownCurState(eInputCode inputCode){
	return (m_CurButtonState & std::bitset<static_cast<int>(eInputCode::_END_)>(std::pow(2, static_cast<int>(inputCode)))).any();
}

bool framework::GamePad::isDownPreState(eInputCode inputCode){
	return (m_PreButtonState & std::bitset<static_cast<int>(eInputCode::_END_)>(std::pow(2, static_cast<int>(inputCode)))).any();
}
