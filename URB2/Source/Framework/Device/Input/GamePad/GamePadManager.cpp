#include "GamePadManager.h"

framework::GamePadManager::GamePadManager(){

}

framework::GamePadManager::~GamePadManager(){

}

void framework::GamePadManager::addGamePad(int padNo){
	m_pGamePadList[padNo] = util::makeShared<GamePad>(padNo);
}

util::WeakPtr<framework::GamePad> framework::GamePadManager::getGamePad(int padNo){
	return m_pGamePadList[padNo];
}
