#include "GamePad.h"
#include <cassert>

framework::GamePad::GamePad():GamePad(-1){
}

framework::GamePad::GamePad(int padNo){
	assert( padNo>=0 &&	"ゲームパッドのコンストラクタには、0以上のパッド番号を入力して下さい。\n\
						デフォルトコンストラクタが呼び出された場合も、このassertが出力します。");
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
