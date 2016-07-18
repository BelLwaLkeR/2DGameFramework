#include "GamePadAggregate.h"
#include <cassert>
#include <Source/Framework/Device/Input/GamePad/GamePad.h>
#include <Source/Framework/Device/Input/GamePad/DxLibGamePad.h>
#include <Source/Framework/Device/Input/GamePad/GamePadInfomationMediator.h>
#include <Source/Utility/Math/Math.h>

framework::GamePadAggregate::GamePadAggregate(){
	m_pDxLibGamePad = util::makeShared<DxLibGamePad>();
	setup();
}

framework::GamePadAggregate::~GamePadAggregate(){

}

void framework::GamePadAggregate::setup(){
	for (int i = 0; i < USE_PAD_NUM; ++i){
		m_pGamePadList.emplace_back(setupGamePad(i));
	}
}

void framework::GamePadAggregate::joinGamePadList(std::vector<util::SharedPtr<IInputDevice>>* inputList){
	for (auto& pad : m_pGamePadList) {
		inputList->emplace_back(pad);
	}
}

util::SharedPtr<framework::GamePad> framework::GamePadAggregate::setupGamePad(int padNo){
	util::SharedPtr<GamePad> pad = util::makeShared<GamePad>(padNo);
	pad->setupDxLibGamePad(m_pDxLibGamePad);
	return pad;
}

inline void framework::GamePadAggregate::assertFallPadNo(int padNo){
	assert(util::Math::isFall(padNo, 0, USE_PAD_NUM));
}
















