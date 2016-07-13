#include "EntityManager.h"
#include <Source/Framework/Component/ComponentFactory.h>


framework::EntityManager::EntityManager(){

}

framework::EntityManager::~EntityManager(){

}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(){
	util::SharedPtr<Entity> entity = util::makeShared<Entity>();
	m_pEntityList.emplace_back(entity);
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const std::string& componentName){
	util::WeakPtr<Entity> entity = addEntity();
	entity->addComponent(componentName);
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const std::vector<std::string>& componentNameList){
	util::WeakPtr<Entity> entity = addEntity();
	for (auto& componentName : componentNameList) {
		entity->addComponent(componentName);
	}
	return entity;
}


void framework::EntityManager::clearEntity(){
	m_pEntityList.clear();
}
