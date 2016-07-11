#include "ComponentFactory.h"
#include <cassert>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Entity/EntityInfomation.h>

framework::ComponentFactory::ComponentFactory(){

}

framework::ComponentFactory::~ComponentFactory(){

}

void framework::ComponentFactory::setupBlueprintList(){
	using namespace component;
//	addBluePrint(CREATE_BLUEPRINT_ARGS(tmpComponent));
	addBluePrint("test", util::makeShared<ComponentCreator<tmpComponent>>());
}

void framework::ComponentFactory::addBluePrint(const std::string & componentName, util::SharedPtr<framework::IComponentCreator> componentPointer){
	m_pComponentBlueprintList[componentName] = componentPointer;
}

void framework::ComponentFactory::clearBlueprintList(){
	m_pComponentBlueprintList.clear();
}





