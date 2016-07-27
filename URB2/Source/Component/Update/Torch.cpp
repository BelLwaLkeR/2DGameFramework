#include "Torch.h"
#include <Source/Framework/Component/LightComponent.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>
#include <Source/Framework/Application/GlobalParameters.h>


component::Torch::Torch() :m_DefaultLightColor({ 0, 0, 0 }), m_DefaultLightIntencity(0), m_LightComponent() {
}

component::Torch::~Torch(){

}

void component::Torch::setup(util::WeakPtr<framework::Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	Component::setup(pEntity, pPosition);
	m_pPosition			= pPosition;
	m_DefaultLightIntencity		= 100;
	m_DefaultLightColor			= {255, 204, 86};
	m_LightComponent.setup(pPosition, m_DefaultLightColor, m_DefaultLightIntencity);
}

void component::Torch::update(){

}
