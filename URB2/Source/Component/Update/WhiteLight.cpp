#include "WhiteLight.h"

component::WhiteLight::WhiteLight()
{
}

component::WhiteLight::~WhiteLight()
{
}

void component::WhiteLight::setup(util::WeakPtr<framework::Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	Component::setup(pEntity, pPosition);
	m_pPosition = pPosition;
	m_LightComponent.setup(pPosition, {255, 255, 255}, 300);
}

void component::WhiteLight::update(){
}
