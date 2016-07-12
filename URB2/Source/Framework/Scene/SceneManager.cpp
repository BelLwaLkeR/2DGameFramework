#include "SceneManager.h"
#include <Source/Framework/Task/TaskManager.h>

framework::SceneManager::SceneManager(){

}

framework::SceneManager::SceneManager(const std::string & firstSceneName){

}

framework::SceneManager::~SceneManager(){
	
}

void framework::SceneManager::load(const std::string & sceneName){

}

void framework::SceneManager::start(){

}

void framework::SceneManager::update(){
	SGLT_TASKMANAGER->updateTask();
}

void framework::SceneManager::draw(){
	SGLT_TASKMANAGER->drawTask();
}

void framework::SceneManager::changeScene(const std::string& nextSceneName){
	SGLT_TASKMANAGER->clearAllTask();

}






