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
	auto itr = std::find(m_pUpdateTaskList.begin(), m_pUpdateTaskList.end(), task);
	if (itr == m_pUpdateTaskList.end()) { return; }
	m_pUpdateTaskList.erase(itr);
}

void framework::TaskManager::removeDrawTask(util::WeakPtr<IDrawTask> task){
	auto itr = std::find(m_pDrawTaskList.begin(), m_pDrawTaskList.end(), task);
	if (itr == m_pDrawTaskList.end()) { return; }
	m_pDrawTaskList.erase(itr);
}

void framework::TaskManager::clearAllTask(){
	m_pUpdateTaskList.clear();
	m_pDrawTaskList.clear();
}

void framework::TaskManager::updateTask(){
	for (auto& task : m_pUpdateTaskList) {
		task->update();
	}
}

void framework::TaskManager::drawTask(){
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
