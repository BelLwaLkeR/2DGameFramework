#include "IUpdateTask.h"

framework::IUpdateTask::IUpdateTask(){
	active();
}

framework::IUpdateTask::~IUpdateTask(){
	deActive();
}
