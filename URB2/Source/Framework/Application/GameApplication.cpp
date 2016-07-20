#include "GameApplication.h"
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Entity/EntityManager.h>
#include <Source/Framework/Component/ComponentNameList.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/ShaderManager.h>

framework::GameApplication::GameApplication(){
}

framework::GameApplication::~GameApplication(){
}

void framework::GameApplication::run(){
	DxLibApplication::run();
}

void framework::GameApplication::initialize(){
	SGLT_SHADER_MANAGER->initialize();
	util::WeakPtr<framework::Entity> entity = SGLT_ENTITY_MANAGER->addEntity();
	entity->addComponent("ControllMove");
	entity->addComponent("DrawTestRobot");
}

void framework::GameApplication::update(){
	SGLT_INPUTMANAGER->update();
	SGLT_TASK_MANAGER->updateTask();
}

void framework::GameApplication::draw(){
	SGLT_TASK_MANAGER->drawTask();
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
