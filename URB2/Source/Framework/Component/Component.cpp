#include "Component.h"
#include <Source/Framework/Entity/EntityInfomation.h>


framework::Component::Component(){

}

framework::Component::Component(util::WeakPtr<EntityInfomation> entityInfo){
	setEntityInfomation(entityInfo);
}

framework::Component::~Component(){

}

void framework::Component::setEntityInfomation(util::WeakPtr<EntityInfomation> entityInfomation){
	m_pEntityInfomation = entityInfomation;
}
