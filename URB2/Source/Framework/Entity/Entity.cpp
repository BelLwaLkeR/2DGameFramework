#pragma once
#include "Entity.h"
#include <Source/Framework/Component/ComponentFactory.h>


void framework::Entity::addComponent(const std::string & componentName){
	SGLT_COMPONENTFACTORY->createComponent(componentName, m_pInfomation);
}

void framework::Entity::addParent(util::WeakPtr<Entity> parent){
	m_pParent = parent;
}

void framework::Entity::addChild(util::WeakPtr<Entity> child){
	m_pChildList.emplace_back(child);
}

const util::WeakPtr<framework::Entity>& framework::Entity::getParent(){
	return m_pParent;
}

const std::list<util::WeakPtr<framework::Entity>>& framework::Entity::getChildList(){
	return m_pChildList;
}

const framework::EntityInfomation & framework::Entity::getInfomation(){
	return *m_pInfomation;
}
