#include "EntityManager.h"
#include <Source/Framework/Component/ComponentFactory.h>


framework::EntityManager::EntityManager(){

}

framework::EntityManager::~EntityManager(){

}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const EntityInfomation& entityInfomation){
	util::SharedPtr<Entity> entity = util::makeShared<Entity>(entityInfomation);
	entity->setMyself(entity);
	m_pEntityList.emplace_back(entity);
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const EntityInfomation& entityInfomation, const std::string& componentName){
	util::WeakPtr<Entity> entity = addEntity(entityInfomation);
	entity->addComponent(componentName);
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const EntityInfomation& entityInfomation, const std::vector<std::string>& componentNameList){
	util::WeakPtr<Entity> entity = addEntity(entityInfomation);
	for (auto& componentName : componentNameList) {
		entity->addComponent(componentName);
	}
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::getEntity(Entity* entity) {
	for (auto& e : m_pEntityList) {
		if (e.get() == entity) { return e; }
	}
	return util::WeakPtr<Entity>();
}


void framework::EntityManager::clearEntity(){
	m_pEntityList.clear();
}
