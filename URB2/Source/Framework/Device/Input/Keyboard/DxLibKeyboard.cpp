#include "DxLibKeyboard.h"

framework::DxLibKeyboard::DxLibKeyboard(){
	setupEKeyCodeMap();
}

framework::DxLibKeyboard::~DxLibKeyboard(){}

bool framework::DxLibKeyboard::isKeyDown(eKeyboardCode keyCode){
	return CheckHitKey(eKeyCodeMap[keyCode]) == 1;
}

void framework::DxLibKeyboard::setupEKeyCodeMap(){

	eKeyCodeMap.clear();
	eKeyCodeMap[eKeyboardCode::ESC]				= KEY_INPUT_ESCAPE;
	eKeyCodeMap[eKeyboardCode::F1]				= KEY_INPUT_F1;
	eKeyCodeMap[eKeyboardCode::F2]				= KEY_INPUT_F2;
	eKeyCodeMap[eKeyboardCode::F3]				= KEY_INPUT_F3;
	eKeyCodeMap[eKeyboardCode::F4]				= KEY_INPUT_F4;
	eKeyCodeMap[eKeyboardCode::F5]				= KEY_INPUT_F5;
	eKeyCodeMap[eKeyboardCode::F6]				= KEY_INPUT_F6;
	eKeyCodeMap[eKeyboardCode::F7]				= KEY_INPUT_F7;
	eKeyCodeMap[eKeyboardCode::F8]				= KEY_INPUT_F8;
	eKeyCodeMap[eKeyboardCode::F9]				= KEY_INPUT_F9;
	eKeyCodeMap[eKeyboardCode::F10]				= KEY_INPUT_F10;
	eKeyCodeMap[eKeyboardCode::F11]				= KEY_INPUT_F11;
	eKeyCodeMap[eKeyboardCode::F12]				= KEY_INPUT_F12;
	eKeyCodeMap[eKeyboardCode::HOME]			= KEY_INPUT_HOME;
	eKeyCodeMap[eKeyboardCode::END]				= KEY_INPUT_END;
	eKeyCodeMap[eKeyboardCode::INSERT]			= KEY_INPUT_INSERT;
	eKeyCodeMap[eKeyboardCode::DELETE_KEY]		= KEY_INPUT_DELETE;
	eKeyCodeMap[eKeyboardCode::_1]				= KEY_INPUT_1;
	eKeyCodeMap[eKeyboardCode::_2]				= KEY_INPUT_2;
	eKeyCodeMap[eKeyboardCode::_3]				= KEY_INPUT_3;
	eKeyCodeMap[eKeyboardCode::_4]				= KEY_INPUT_4;
	eKeyCodeMap[eKeyboardCode::_5]				= KEY_INPUT_5;
	eKeyCodeMap[eKeyboardCode::_6]				= KEY_INPUT_6;
	eKeyCodeMap[eKeyboardCode::_7]				= KEY_INPUT_7;
	eKeyCodeMap[eKeyboardCode::_8]				= KEY_INPUT_8;
	eKeyCodeMap[eKeyboardCode::_9]				= KEY_INPUT_9;
	eKeyCodeMap[eKeyboardCode::_0]				= KEY_INPUT_0;
	eKeyCodeMap[eKeyboardCode::A]				= KEY_INPUT_A;
	eKeyCodeMap[eKeyboardCode::B]				= KEY_INPUT_B;
	eKeyCodeMap[eKeyboardCode::C]				= KEY_INPUT_C;
	eKeyCodeMap[eKeyboardCode::D]				= KEY_INPUT_D;
	eKeyCodeMap[eKeyboardCode::E]				= KEY_INPUT_E;
	eKeyCodeMap[eKeyboardCode::F]				= KEY_INPUT_F;
	eKeyCodeMap[eKeyboardCode::G]				= KEY_INPUT_G;
	eKeyCodeMap[eKeyboardCode::H]				= KEY_INPUT_H;
	eKeyCodeMap[eKeyboardCode::I]				= KEY_INPUT_I;
	eKeyCodeMap[eKeyboardCode::J]				= KEY_INPUT_J;
	eKeyCodeMap[eKeyboardCode::K]				= KEY_INPUT_K;
	eKeyCodeMap[eKeyboardCode::L]				= KEY_INPUT_L;
	eKeyCodeMap[eKeyboardCode::M]				= KEY_INPUT_M;
	eKeyCodeMap[eKeyboardCode::N]				= KEY_INPUT_N;
	eKeyCodeMap[eKeyboardCode::O]				= KEY_INPUT_O;
	eKeyCodeMap[eKeyboardCode::P]				= KEY_INPUT_P;
	eKeyCodeMap[eKeyboardCode::Q]				= KEY_INPUT_Q;
	eKeyCodeMap[eKeyboardCode::R]				= KEY_INPUT_R;
	eKeyCodeMap[eKeyboardCode::S]				= KEY_INPUT_S;
	eKeyCodeMap[eKeyboardCode::T]				= KEY_INPUT_T;
	eKeyCodeMap[eKeyboardCode::U]				= KEY_INPUT_U;
	eKeyCodeMap[eKeyboardCode::V]				= KEY_INPUT_V;
	eKeyCodeMap[eKeyboardCode::W]				= KEY_INPUT_W;
	eKeyCodeMap[eKeyboardCode::X]				= KEY_INPUT_X;
	eKeyCodeMap[eKeyboardCode::Y]				= KEY_INPUT_Y;
	eKeyCodeMap[eKeyboardCode::Z]				= KEY_INPUT_Z;
	eKeyCodeMap[eKeyboardCode::BACKSPACE]		= KEY_INPUT_BACK;
	eKeyCodeMap[eKeyboardCode::TAB]				= KEY_INPUT_TAB;
	eKeyCodeMap[eKeyboardCode::ENTER]			= KEY_INPUT_RETURN;
	eKeyCodeMap[eKeyboardCode::SPACE]			= KEY_INPUT_SPACE;
	eKeyCodeMap[eKeyboardCode::SHIFT_LEFT]		= KEY_INPUT_LSHIFT;
	eKeyCodeMap[eKeyboardCode::SHIFT_RIGHT]		= KEY_INPUT_RSHIFT;
	eKeyCodeMap[eKeyboardCode::CTRL_LEFT]		= KEY_INPUT_LCONTROL;
	eKeyCodeMap[eKeyboardCode::CTRL_RIGHT]		= KEY_INPUT_RCONTROL;
	eKeyCodeMap[eKeyboardCode::ALT_LEFT]		= KEY_INPUT_LALT;
	eKeyCodeMap[eKeyboardCode::ALT_RIGHT]		= KEY_INPUT_RALT;
	eKeyCodeMap[eKeyboardCode::PAGE_UP]			= KEY_INPUT_PGUP;
	eKeyCodeMap[eKeyboardCode::PAGE_DOWN]		= KEY_INPUT_PGDN;
	eKeyCodeMap[eKeyboardCode::UP]				= KEY_INPUT_UP;
	eKeyCodeMap[eKeyboardCode::DOWN]			= KEY_INPUT_DOWN;
	eKeyCodeMap[eKeyboardCode::LEFT]			= KEY_INPUT_LEFT;
	eKeyCodeMap[eKeyboardCode::RIGHT]			= KEY_INPUT_RIGHT;

}
