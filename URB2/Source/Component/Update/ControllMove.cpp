#include "ControllMove.h"
#include <Source/Framework/Device/Input/InputManager.h>
#include <Source/Utility/Type/Vector2.h>
#include <DxLib.h>

component::ControllMove::ControllMove(){
	speed = 5.f;
}

component::ControllMove::~ControllMove(){

}

void component::ControllMove::update(){
	move();
}

void component::ControllMove::move(){
	if (SGLT_INPUT_MANAGER->isKeyDownAny(framework::eInputCode::UP))	{ moveUp();		}
	if (SGLT_INPUT_MANAGER->isKeyDownAny(framework::eInputCode::DOWN))	{ moveDown();	}
	if (SGLT_INPUT_MANAGER->isKeyDownAny(framework::eInputCode::LEFT))	{ moveLeft();	}
	if (SGLT_INPUT_MANAGER->isKeyDownAny(framework::eInputCode::RIGHT))	{ moveRight();	}
}

void component::ControllMove::moveUp(){
	m_pPosition->Y -= speed;
}

void component::ControllMove::moveDown(){
	m_pPosition->Y += speed;
}

void component::ControllMove::moveLeft(){
	m_pPosition->X -= speed;
}

void component::ControllMove::moveRight(){
	m_pPosition->X += speed;
}
