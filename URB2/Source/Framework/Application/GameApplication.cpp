#include "GameApplication.h"
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Define.h>

framework::GameApplication::GameApplication(){
}

framework::GameApplication::~GameApplication(){
}

void framework::GameApplication::initialize(){
}

void framework::GameApplication::update(){
	input.update();
	SGLT_TASKMANAGER->taskUpdate();
}

void framework::GameApplication::draw(){
}

void framework::GameApplication::finalize(){
}

bool framework::GameApplication::isEnd(){
	bool isEnd = false;
#ifdef DEBUG_MODE
	isEnd |= input.isKeyDown(eInputCode::EXIT);
#else
#endif
	return isEnd;
}

void framework::GameApplication::setupWindowConfig(){
	DxLibApplication::setupWindowConfig(WindowConfig("UnlimitedRespawnBravers2", 1280, 720, 32, 60, false));
}
