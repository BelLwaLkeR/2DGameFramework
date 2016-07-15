#include "GamePadManager.h"
#include <cassert>
#include <Source/Framework/Device/Input/GamePad/GamePad.h>
#include <Source/Framework/Device/Input/GamePad/DxLibGamePad.h>
#include <Source/Framework/Device/Input/GamePad/GamePadInfomationMediator.h>
#include <Source/Framework/Device/Input/GamePad/GamePadManager.h>
#include <Source/Utility/Math/Math.h>

framework::GamePadManager::GamePadManager(){
	m_pDxLibGamePad = util::makeShared<DxLibGamePad>();
	setup();
}

framework::GamePadManager::~GamePadManager(){

}

void framework::GamePadManager::setup(){
	for (int i = 0; i < USE_PAD_NUM; ++i){
		m_pGamePadList.emplace_back(setupGamePad(i));
	}
}

//void framework::GamePadManager::update(){
//	for (auto& pad : m_pGamePadList) {
//		pad->update();
//	}
//}
//
//bool framework::GamePadManager::isKeyDown(int padNo, eInputCode inputCode){
//	return m_pGamePadList[padNo]->isKeyDown(inputCode);
//}
//
//bool framework::GamePadManager::isKeyUp(int padNo, eInputCode inputCode){
//	return m_pGamePadList[padNo]->isKeyUp(inputCode);
//}
//
//bool framework::GamePadManager::isKeyPush(int padNo, eInputCode inputCode){
//	return m_pGamePadList[padNo]->isKeyPush(inputCode);
//}
//
//bool framework::GamePadManager::isKeyRelease(int padNo, eInputCode inputCode){
//	return m_pGamePadList[padNo]->isKeyRelease(inputCode);
//}

void framework::GamePadManager::joinGamePadList(std::vector<util::SharedPtr<IInputDevice>>* inputList){
	for (auto& pad : m_pGamePadList) {
		inputList->emplace_back(pad);
	}
}

util::SharedPtr<framework::GamePad> framework::GamePadManager::setupGamePad(int padNo){
	util::SharedPtr<GamePad> pad = util::makeShared<GamePad>(padNo);
	pad->setupDxLibGamePad(m_pDxLibGamePad);
	return pad;
}

inline void framework::GamePadManager::assertFallPadNo(int padNo){
	assert(util::Math::isFall(padNo, 0, USE_PAD_NUM));
}
















