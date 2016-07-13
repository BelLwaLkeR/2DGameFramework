#include "DrawComponent.h"
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Entity/Entity.h>

framework::DrawComponent::DrawComponent(){
}

framework::DrawComponent::~DrawComponent(){
}

void framework::DrawComponent::active() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASKMANAGER->addDrawTask(drawTask);
}

void framework::DrawComponent::deActive() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASKMANAGER->removeDrawTask(drawTask);
}
