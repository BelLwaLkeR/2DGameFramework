#include "DrawComponent.h"
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Entity/Entity.h>

framework::DrawComponent::DrawComponent(){
	m_Layer = framework::eDrawLayer::UI;
}

framework::DrawComponent::DrawComponent(eDrawLayer layer){
	m_Layer = layer;
}

framework::DrawComponent::~DrawComponent(){

}

void framework::DrawComponent::draw(){
	

}

void framework::DrawComponent::active() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASKMANAGER->addDrawTask(m_Layer, drawTask);
}

void framework::DrawComponent::deActive() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASKMANAGER->removeDrawTask(m_Layer, drawTask);
}
