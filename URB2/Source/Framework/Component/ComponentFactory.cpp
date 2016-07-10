#include "ComponentFactory.h"
#include <cassert>
#include <Source/Framework/Component/Component.h>


framework::ComponentFactory::ComponentFactory(){
}

framework::ComponentFactory::~ComponentFactory(){
}

void framework::ComponentFactory::setupBlueprintList(){
	using namespace component;
//	addBluePrint(CREATE_BLUEPRINT_ARGS(tmpComponent));
	addBluePrint("tmpComponent", new tmpComponent());



}

void framework::ComponentFactory::addBluePrint(const std::string & componentName, util::SharedPtr<framework::IComponentMaker> componentPointer){
	m_pComponentBlueprintList[componentName] = componentPointer;
}

void framework::ComponentFactory::addBluePrint(const std::string & componentName, Component* componentPointer){
	m_pComponentBlueprintList[componentName] = util::SharedPtr<Component>(componentPointer);
}

util::SharedPtr<framework::Component> framework::ComponentFactory::createComponent(const std::string & componentName){
	assert(m_pComponentBlueprintList.find(componentName) != m_pComponentBlueprintList.end() && "生成するコンポーネントが生成されていません。");
	return util::SharedPtr<Component>(m_pComponentBlueprintList[componentName]->create());
}

void framework::ComponentFactory::clearBlueprintList(){
}
