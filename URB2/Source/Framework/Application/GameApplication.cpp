#include "GameApplication.h"
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Entity/EntityManager.h>
#include <Source/Framework/Component/ComponentNameList.h>

framework::GameApplication::GameApplication(){
}

framework::GameApplication::~GameApplication(){
}

void framework::GameApplication::run(){
	DxLibApplication::run();
}

void framework::GameApplication::initialize(){
//	sceneManager.load("testScene");
	util::WeakPtr<framework::Entity> entity = SGLT_ENTITYMANAGER->addEntity();
	entity->addComponent("ControllMove");
	entity->addComponent("DrawRectangle");
}

void framework::GameApplication::update(){
	SGLT_INPUTMANAGER->update();
	SGLT_TASKMANAGER->updateTask();
}

void framework::GameApplication::draw(){
	SGLT_TASKMANAGER->drawTask();
}

void framework::GameApplication::finalize(){
	
}

bool framework::GameApplication::isEnd(){
	bool isEnd = false;
#ifdef DEBUG_MODE
	isEnd |= SGLT_INPUTMANAGER->isKeyDown(eInputCode::EXIT).any();
#else
#endif
	return isEnd;
}

void framework::GameApplication::setupWindowConfig(){
	DxLibApplication::setupWindowConfig(WindowConfig("UnlimitedRespawnBravers2", 1280, 720, 32, 60, false));
}
