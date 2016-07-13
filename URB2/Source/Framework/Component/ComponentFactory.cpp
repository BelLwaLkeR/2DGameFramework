#include "ComponentFactory.h"
#include <cassert>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>
#include <Source/Component/ControllMove.h>
#include <Source/Component/DrawRectangle.h>

framework::ComponentFactory::ComponentFactory(){
	setupBlueprintList();
}

framework::ComponentFactory::~ComponentFactory(){

}

void framework::ComponentFactory::setupBlueprintList(){
	using namespace component;
	addBluePrint(CREATE_BLUEPRINT_ARGS(tmpComponent));
	addBluePrint(CREATE_BLUEPRINT_ARGS(ControllMove));
	addBluePrint(CREATE_BLUEPRINT_ARGS(DrawRectangle));
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





