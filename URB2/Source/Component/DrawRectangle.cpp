#include "DrawRectangle.h"
#include <DxLib.h>
#include <Source/Utility/Type/Vector2.h>


component::DrawRectangle::DrawRectangle(){
}

component::DrawRectangle::~DrawRectangle(){

}

void component::DrawRectangle::draw(){

	int width		= 20;
	int height		= 20;
	int posTop		= m_pPosition->getIntY() - height / 2;
	int posBottom	= m_pPosition->getIntY() + height / 2;
	int posLeft		= m_pPosition->getIntX() - width / 2;
	int posRight	= m_pPosition->getIntX() + width / 2;
	DrawBox(posLeft, posTop, posRight, posBottom, GetColor(0, 255, 128), TRUE);
	
}
