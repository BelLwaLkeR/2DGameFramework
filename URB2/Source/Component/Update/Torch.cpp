#include "Torch.h"
#include <Source/Framework/Component/LightComponent.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>


component::Torch::Torch(){

}

component::Torch::~Torch(){

}

void component::Torch::setup(util::WeakPtr<framework::Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	Component::setup(pEntity, pPosition);
	m_pPosition			= pPosition;
	m_LightComponent.initialize(pPosition, {255, 204, 86}, 100);
}

void component::Torch::update(){

}
