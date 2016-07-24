#include "DxLibApplication.h"
#include <cassert>
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Define.h>

/**
* @file			DxLibApplication.cpp
* @namespace	framework
* @brief		DxLibを用いたメインループの原型。
* @author		大森 健司
*/


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
		update();
		draw();
		adjustFPS();
	}
	finalize();
}

void framework::DxLibApplication::setupWindow(const WindowConfig& windowConfig){
	SetWindowSizeChangeEnableFlag(windowConfig.canChangeWindowSize);
	SetMainWindowText(windowConfig.title.c_str());
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

void framework::DxLibApplication::setupGraphicConfig(){
	SetUseDirect3DVersion(DX_DIRECT3D_9);
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
	setupGraphicConfig();
	if (DxLib_Init() == -1) { assert(!"DxLibの初期化に失敗しました。"); };

}






