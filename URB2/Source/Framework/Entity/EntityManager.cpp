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

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(util::SharedPtr<std::string> component){
	util::WeakPtr<Entity> entity = addEntity();
	SGLT_COMPONENTFACTORY->createComponent(*component, entity->getInfomation());
	return entity;
}

util::WeakPtr<framework::Entity> framework::EntityManager::addEntity(const std::vector<std::string>& componentList){
	util::WeakPtr<Entity> entity = addEntity();
	for (auto& component : componentList) {
		SGLT_COMPONENTFACTORY->createComponent(component, entity->getInfomation());
	}
	return entity;
}


void framework::EntityManager::clearEntity(){
	m_pEntityList.clear();
}
