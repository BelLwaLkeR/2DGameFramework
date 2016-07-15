#include "DxLibGamePad.h"
#include <DxLib.h>
#include <Source/Framework/Device/Input/GamePad/GamePadInfomationMediator.h>

framework::DxLibGamePad::DxLibGamePad(){

}

framework::DxLibGamePad::~DxLibGamePad(){

}

bool framework::DxLibGamePad::isKeyDown(int padNo, eInputCode code){
	int padCode		= GamePadInfomationMediator::getPadButtonCode(code);
	int deviceNo	= GamePadInfomationMediator::getDeviceNo(padNo);
	return (GetJoypadInputState(deviceNo) & padCode) > 0;
}


