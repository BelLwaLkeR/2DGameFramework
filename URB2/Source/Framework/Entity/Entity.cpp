#pragma once
#include "Entity.h"
#include <Source/Framework/Component/Component.h>
#include <algorithm>


framework::Entity::Entity(EntityInfomation entityInfomation):m_pComponentList(){
	m_pInfomation	= util::makeShared<EntityInfomation>(entityInfomation);
}

framework::Entity::~Entity(){
}

void framework::Entity::setMyself(util::WeakPtr<Entity> pMyselfEntity){
	m_pEntity = pMyselfEntity;
}

void framework::Entity::addComponent(const std::string & componentName){
	util::SharedPtr<Component> component = SGLT_COMPONENT_FACTORY->createComponent(componentName);
	m_pComponentList.emplace_back(component);
	component->setup(m_pEntity, m_pInfomation->pPosition);
	component->active();
}

void framework::Entity::addParent(util::WeakPtr<Entity> parent){
	m_pParent = parent;
}

void framework::Entity::addChild(util::WeakPtr<Entity> child){
	m_pChildList.emplace_back(child);
}

const util::WeakPtr<framework::Entity>& framework::Entity::getEntity() const{
	return m_pEntity;
}

const util::WeakPtr<framework::Component> framework::Entity::getComponent(Component* component) const{
	auto& itr = std::find_if(m_pComponentList.begin(), m_pComponentList.end(), [&](util::SharedPtr<Component> thisComponent) {
		return thisComponent.get() == component;
	});
	return util::WeakPtr<Component>();
}

const std::list<util::WeakPtr<framework::Component>>& framework::Entity::getComponentList() const{
	return std::list<util::WeakPtr<Component>>();
}

const util::WeakPtr<framework::Entity>& framework::Entity::getParent() const{
	return m_pParent;
}

const std::list<util::WeakPtr<framework::Entity>>& framework::Entity::getChildList() const{
	return m_pChildList;
}


