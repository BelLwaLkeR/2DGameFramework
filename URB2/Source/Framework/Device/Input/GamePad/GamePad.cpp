#include "GamePad.h"
#include <cassert>
#include <Source/Framework/Device/Input/GamePad/DxLibGamePad.h>

framework::GamePad::GamePad():GamePad(-1){
}

framework::GamePad::GamePad(int padNo){
	assert( padNo>=0 &&	"�Q�[���p�b�h�̃R���X�g���N�^�ɂ́A0�ȏ�̃p�b�h�ԍ�����͂��ĉ������B\n\
						�f�t�H���g�R���X�g���N�^���Ăяo���ꂽ�ꍇ���A����assert���o�͂��܂��B");
	m_PadNo = padNo;
}

framework::GamePad::~GamePad(){
}

void framework::GamePad::setupDxLibGamePad(util::WeakPtr<DxLibGamePad> pDxLibGamePad){
	m_pDxLibGamePad = pDxLibGamePad;
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
	m_CurButtonState.reset();
	for (int i = 0; i < (int)eInputCode::_END_; ++i) {
		if (m_pDxLibGamePad->isKeyDown(m_PadNo, (eInputCode)i)) {
			m_CurButtonState.set(i);
		}
	}
}

bool framework::GamePad::isDownCurState(eInputCode inputCode){
	return (m_CurButtonState & std::bitset<(int)eInputCode::_END_>(std::pow(2, (int)inputCode))).any();
}

bool framework::GamePad::isDownPreState(eInputCode inputCode){
	return (m_PreButtonState & std::bitset<(int)eInputCode::_END_>(std::pow(2, (int)inputCode))).any();
}
