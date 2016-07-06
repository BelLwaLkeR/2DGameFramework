#include "IDrawTask.h"
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Utility/SmartPtr.h>

framework::IDrawTask::IDrawTask(){
	active();
}

framework::IDrawTask::~IDrawTask(){
	deActive();
}

void framework::IDrawTask::active(){
	SGLT_TASKMANAGER.lock()->addDrawTask(util::SharedPtr<IDrawTask>(this));
}

void framework::IDrawTask::deActive(){
	SGLT_TASKMANAGER->removeDrawTask(util::SharedPtr<IDrawTask>(this));
}
