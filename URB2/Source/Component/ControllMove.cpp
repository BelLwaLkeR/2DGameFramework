#include "ControllMove.h"
#include <Source/Framework/Device/Input/InputManager.h>

component::ControllMove::ControllMove(){

}

component::ControllMove::~ControllMove(){

}

void component::ControllMove::update(){
	if (SGLT_INPUTMANAGER->isKeyDown(framework::eInputCode::UP))	{ m_pEntityInfomation->position.Y -= 5; }
	if (SGLT_INPUTMANAGER->isKeyDown(framework::eInputCode::DOWN))	{ m_pEntityInfomation->position.Y += 5; }
	if (SGLT_INPUTMANAGER->isKeyDown(framework::eInputCode::LEFT))	{ m_pEntityInfomation->position.X -= 5; }
	if (SGLT_INPUTMANAGER->isKeyDown(framework::eInputCode::RIGHT))	{ m_pEntityInfomation->position.X += 5; }
}
