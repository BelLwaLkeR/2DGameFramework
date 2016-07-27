#include "TaskManager.h"
#include <Source/Framework/Component/UpdateComponent.h>
#include <Source/Framework/Component/DrawComponent.h>

framework::TaskManager::TaskManager(){

}

framework::TaskManager::~TaskManager(){

}

void framework::TaskManager::initialize(){
	m_Screen.initialize();
}

void framework::TaskManager::addUpdateTask(util::WeakPtr<UpdateComponent> task){
	if (isInUpdateTaskList(task)) { return; }
	m_pUpdateTaskList.addTask(task);
}

void framework::TaskManager::addDrawTask(framework::eDrawLayer layer, util::WeakPtr<DrawComponent> task){
//	if (isInDrawTaskList(task)) { return; }
	m_pDrawTaskList[layer].addTask(task);
}

void framework::TaskManager::removeUpdateTask(util::WeakPtr<UpdateComponent> task){
	m_pUpdateTaskList.removeTask(task);
}

void framework::TaskManager::removeDrawTask(framework::eDrawLayer layer, util::WeakPtr<DrawComponent> task){
	m_pDrawTaskList[layer].removeTask(task);
}

void framework::TaskManager::clearAllTask(){
	m_pUpdateTaskList.clearAllTask();
	m_pDrawTaskList.clear();
}

void framework::TaskManager::updateTask(){
	m_pUpdateTaskList.refleshTask();
	for (auto& task : m_pUpdateTaskList.getTaskList()) {
		task->update();
	}
}

void framework::TaskManager::drawTask(){
	m_Screen.changeDrawTargetGameScreen();
	for (int i = 0; i < (int)eDrawLayer::_END_; ++i) {
		drawTaskLayerd((eDrawLayer)i);
	}
	m_Screen.drawToApplication();
}

void framework::TaskManager::drawTaskLayerd(eDrawLayer layer){
	m_pDrawTaskList[layer].refleshTask();
	for (auto& task : m_pDrawTaskList[layer].getTaskList()) {
		task->draw();
	}
}

bool framework::TaskManager::isInUpdateTaskList(util::WeakPtr<UpdateComponent> task){
	const auto& itr = std::find(m_pUpdateTaskList.getTaskList().begin(), m_pUpdateTaskList.getTaskList().end(), task);
	return itr != m_pUpdateTaskList.getTaskList().end();
}

bool framework::TaskManager::isInDrawTaskList(util::WeakPtr<DrawComponent> task){
	for (int i = 0; i < (int)eDrawLayer::_END_; ++i) {
		if (isInDrawTaskList((eDrawLayer)i, task)) { return true; }
	}
	return false;
}

bool framework::TaskManager::isInDrawTaskList(eDrawLayer layer, util::WeakPtr<DrawComponent> task){
	const auto& itr = std::find(m_pDrawTaskList[layer].getTaskList().begin(), m_pDrawTaskList[layer].getTaskList().end(),task);
	return itr != m_pDrawTaskList[layer].getTaskList().end();

}






