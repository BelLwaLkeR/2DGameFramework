#include "TaskManager.h"
#include <Source/Framework/Component/UpdateComponent.h>
#include <Source/Framework/Component/DrawComponent.h>

framework::TaskManager::TaskManager(){


}

framework::TaskManager::~TaskManager(){


}

void framework::TaskManager::addUpdateTask(util::WeakPtr<UpdateComponent> task){
	if (isInUpdateTaskList(task)) { return; }
	m_pUpdateTaskList.emplace_back(task);
}

void framework::TaskManager::addDrawTask(util::WeakPtr<DrawComponent> task){
	if (isInDrawTaskList(task)) { return; }
	m_pDrawTaskList.emplace_back(task);
}

void framework::TaskManager::removeUpdateTask(util::WeakPtr<UpdateComponent> task){
	auto itr = std::find(m_pUpdateTaskList.begin(), m_pUpdateTaskList.end(), task);
	if (itr == m_pUpdateTaskList.end()) { return; }
	m_pUpdateTaskList.erase(itr);
}

void framework::TaskManager::removeDrawTask(util::WeakPtr<DrawComponent> task){
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

bool framework::TaskManager::isInUpdateTaskList(util::WeakPtr<UpdateComponent> task){
	bool isFind = true;
	return false;
}

bool framework::TaskManager::isInDrawTaskList(util::WeakPtr<DrawComponent> task){
	bool isFind = true;
	return false;
}






