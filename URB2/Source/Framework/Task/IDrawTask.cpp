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
	

}

void framework::IDrawTask::deActive(){


}
