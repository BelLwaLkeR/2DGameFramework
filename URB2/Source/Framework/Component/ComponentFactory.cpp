#include "ComponentFactory.h"
#include <cassert>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Component/Update/ControllMove.h>
#include <Source/Component/Update/Torch.h>
#include <Source/Component/Draw/DrawRectangle.h>
#include <Source/Component/Draw/DrawTestRobot.h>
#include <Source/Component/Draw/DrawTreasureBox.h>

framework::ComponentFactory::ComponentFactory(){
	setupBlueprintList();
}

framework::ComponentFactory::~ComponentFactory(){

}

void framework::ComponentFactory::setupBlueprintList(){
	using namespace component;
	addBluePrint(CREATE_BLUEPRINT_ARGS(ControllMove));
	addBluePrint(CREATE_BLUEPRINT_ARGS(DrawRectangle));
	addBluePrint(CREATE_BLUEPRINT_ARGS(DrawTestRobot));
	addBluePrint(CREATE_BLUEPRINT_ARGS(DrawTreasureBox));
	addBluePrint(CREATE_BLUEPRINT_ARGS(Torch));
}

void framework::ComponentFactory::addBluePrint(const std::string & componentName, util::SharedPtr<framework::IComponentCreator> componentPointer){
	m_pComponentBlueprintList[componentName] = componentPointer;
}

void framework::ComponentFactory::clearBlueprintList(){
	m_pComponentBlueprintList.clear();
}

util::SharedPtr<framework::Component> framework::ComponentFactory::createComponent(const std::string& componentName){
	assert(m_pComponentBlueprintList.find(componentName) != m_pComponentBlueprintList.end() && "生成するコンポーネントがComponentFactoryのBlueprintに登録されていません。");
	return m_pComponentBlueprintList[componentName]->create();
}





