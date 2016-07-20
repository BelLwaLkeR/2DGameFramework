#include "UpdateComponent.h"
#include <Source/Framework/Entity/Entity.h>
#include <Source/Framework/Task/TaskManager.h>

framework::UpdateComponent::UpdateComponent(){

}

framework::UpdateComponent::~UpdateComponent(){

}

void framework::UpdateComponent::active(){
	util::WeakPtr<UpdateComponent> updateTask = m_pEntity->getComponentCast<UpdateComponent>(this);
	SGLT_TASK_MANAGER->addUpdateTask(updateTask);
}

void framework::UpdateComponent::deActive(){
	util::WeakPtr<UpdateComponent> updateTask = m_pEntity->getComponentCast<UpdateComponent>(this);
	SGLT_TASK_MANAGER->removeUpdateTask(updateTask);
}









