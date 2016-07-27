#include "GameApplication.h"
#include <Source/Framework/Window/WindowConfig.h>
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Define.h>
#include <Source/Framework/Entity/EntityManager.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>
#include <Source/Framework/Component/ComponentNameList.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Shader/ShaderManager.h>
#include <Source/Component/Draw/DrawTestRobot.h>
#include <Source/Component/Update/Torch.h>


framework::GameApplication::GameApplication(){
}

framework::GameApplication::~GameApplication(){
}

void framework::GameApplication::run(){
	DxLibApplication::run();
}

void framework::GameApplication::initialize(){
	SGLT_SHADER_MANAGER->initialize();
	SGLT_TASK_MANAGER->initialize();
	util::WeakPtr<framework::Entity> player = SGLT_ENTITY_MANAGER->addEntity({ "testObject", "player", 0, { 500, 500 } });
//	const std::string& name, const util::Hash& hash, unsigned int id, const util::Vector2& position;
	player->addComponent("Torch");
	player->addComponent("ControllMove");
	player->addComponent("DrawTestRobot");

	util::WeakPtr<framework::Entity> TreasureBox = SGLT_ENTITY_MANAGER->addEntity({ "testObject", "object", 0,{ 500, 200 } });
	TreasureBox->addComponent("DrawTreasureBox");

	util::WeakPtr<framework::Entity> testLight = SGLT_ENTITY_MANAGER->addEntity({ "testLignth", "object", 0,{ 0, 0 } });
//	testLight->addComponent("Torch");
}

void framework::GameApplication::update(){
	SGLT_INPUT_MANAGER->update();
	SGLT_LIGHT_AGGREGATE->reloadLight();
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
	isEnd |= SGLT_INPUT_MANAGER->isKeyDown(eInputCode::EXIT).any();
#else
#endif
	return isEnd;
}

void framework::GameApplication::setupWindowConfig(){
	DxLibApplication::setupWindowConfig(WindowConfig("UnlimitedRespawnBravers2", 1280, 720, 32, 60, false));
}
