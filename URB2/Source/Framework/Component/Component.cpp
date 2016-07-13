#include "Component.h"
#include <Source/Framework/Entity/Entity.h>
#include <Source/Utility/Type/Vector2.h>


framework::Component::Component(){

}

framework::Component::Component(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	setEntityPtr(pEntity);
	setPositionPtr(pPosition);
}

framework::Component::~Component(){

}

void framework::Component::setup(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	setEntityPtr(pEntity);
	setPositionPtr(pPosition);
}

void framework::Component::setPositionPtr(util::WeakPtr<util::Vector2> pPosition){
	m_pPosition = pPosition;
}

void framework::Component::setEntityPtr(util::WeakPtr<Entity> pEntity){
	m_pEntity = pEntity;
}



