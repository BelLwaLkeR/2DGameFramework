#include "TaskManager.h"
#include <Source/Framework/Task/IUpdateTask.h>
#include <Source/Framework/Task/IDrawTask.h>

framework::TaskManager::TaskManager(){


}

framework::TaskManager::~TaskManager(){


}

void framework::TaskManager::addUpdateTask(util::WeakPtr<IUpdateTask> task){
	if (isInUpdateTaskList(task)) { return; }
	m_pUpdateTaskList.emplace_back(task);
}

void framework::TaskManager::addDrawTask(util::WeakPtr<IDrawTask> task){
	if (isInDrawTaskList(task)) { return; }
	m_pDrawTaskList.emplace_back(task);
}

void framework::TaskManager::removeUpdateTask(util::WeakPtr<IUpdateTask> task){
	m_pUpdateTaskList.erase(task);
}

void framework::TaskManager::removeDrawTask(util::WeakPtr<IDrawTask> task){
}

void framework::TaskManager::taskUpdate(){
	for (auto& task : m_pUpdateTaskList) {
		task->update();
	}
}

void framework::TaskManager::taskDraw(){
	for(auto& task: m_pDrawTaskList){
		task->draw();
	}
}

bool framework::TaskManager::isInUpdateTaskList(util::WeakPtr<IUpdateTask> task){
	bool isFind = true;
	

	return false;
}

bool framework::TaskManager::isInDrawTaskList(util::WeakPtr<IDrawTask> task){
	bool isFind = true;

	return false;
}
