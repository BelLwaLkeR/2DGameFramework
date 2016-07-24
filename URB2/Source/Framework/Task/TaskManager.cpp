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
	m_pUpdateTaskList.emplace_back(task);
}

void framework::TaskManager::addDrawTask(framework::eDrawLayer layer, util::WeakPtr<DrawComponent> task){
//	if (isInDrawTaskList(task)) { return; }
	m_pDrawTaskList[layer].emplace_back(task);
}

void framework::TaskManager::removeUpdateTask(util::WeakPtr<UpdateComponent> task){
	auto itr = std::find(m_pUpdateTaskList.begin(), m_pUpdateTaskList.end(), task);
	if (itr == m_pUpdateTaskList.end()) { return; }
	m_pUpdateTaskList.erase(itr);
}

void framework::TaskManager::removeDrawTask(framework::eDrawLayer layer, util::WeakPtr<DrawComponent> task){
	auto itr = std::find(m_pDrawTaskList[layer].begin(), m_pDrawTaskList[layer].end(), task);
	if (itr != m_pDrawTaskList[layer].end()) {
		m_pDrawTaskList[layer].erase(itr);
		return;
	}	
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
	m_Screen.changeDrawTargetGameScreen();
	for (int i = 0; i < (int)eDrawLayer::_END_; ++i) {
		drawTaskLayerd((eDrawLayer)i);
	}
	m_Screen.drawToApplication();
}

void framework::TaskManager::drawTaskLayerd(eDrawLayer layer){
	for (auto& task : m_pDrawTaskList[layer]) {
		task->draw();
	}
}

bool framework::TaskManager::isInUpdateTaskList(util::WeakPtr<UpdateComponent> task){
	const auto& itr = std::find(m_pUpdateTaskList.begin(), m_pUpdateTaskList.end(), task);
	return itr != m_pUpdateTaskList.end();
}

bool framework::TaskManager::isInDrawTaskList(util::WeakPtr<DrawComponent> task){
	for (int i = 0; i < (int)eDrawLayer::_END_; ++i) {
		if (isInDrawTaskList((eDrawLayer)i, task)) { return true; }
	}
	return false;
}

bool framework::TaskManager::isInDrawTaskList(eDrawLayer layer, util::WeakPtr<DrawComponent> task){
	const auto& itr = std::find(m_pDrawTaskList[layer].begin(), m_pDrawTaskList[layer].end(),task);
	return itr != m_pDrawTaskList[layer].end();

}






