#include "DxLibApplication.h"
#include <cassert>
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Define.h>


framework::DxLibApplication::DxLibApplication(){


}

framework::DxLibApplication::~DxLibApplication(){


}

bool framework::DxLibApplication::isEnd(){ return false; }

void framework::DxLibApplication::setupWindowConfig(const WindowConfig & windowConfig){
	setupWindow(windowConfig);
}

void framework::DxLibApplication::adjustFPS(){}

void framework::DxLibApplication::run(){
	setup();
	initialize();
	while (!isApplicationEnd() && !isEnd()) {
		refreshScreen();
		update();
		draw();
		adjustFPS();
	}
	finalize();
}

void framework::DxLibApplication::setupWindow(const WindowConfig& windowConfig){
	SetWindowSizeChangeEnableFlag(windowConfig.canChangeWindowSize);
	SetMainWindowText(windowConfig.title.c_str());
	SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(windowConfig.width, windowConfig.height, windowConfig.colorBit);
	ChangeWindowMode(!windowConfig.isFullScreen);

}

void framework::DxLibApplication::setLogOutput(){
#ifdef DEBUG_MODE
	SetOutApplicationLogValidFlag(TRUE);
#else
	SetOutApplicationLogValidFlag(FALSE);
#endif
}

bool framework::DxLibApplication::isApplicationEnd(){
	return ProcessMessage()!=0;
}

void framework::DxLibApplication::teardown(){
	DxLib_End();
}

void framework::DxLibApplication::setup(){
	setLogOutput();
	setupWindowConfig();
	if (DxLib_Init() == -1) { assert(!"DxLibの初期化に失敗しました。"); };

}

void framework::DxLibApplication::refreshScreen(){
	ScreenFlip();
	ClearDrawScreen();
}
