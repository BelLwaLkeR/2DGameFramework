#include "LightComponent.h"
#include <Source/Framework/Device/Renderer/ImageRenderer/Light.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/LightingAggregate.h>

framework::LightComponent::LightComponent(){
	m_pLight = util::makeShared<Light>();
}

framework::LightComponent::~LightComponent(){
}

void framework::LightComponent::initialize(util::WeakPtr<util::Vector2> pPosition, const util::Color color, float intencity){
	m_pPosition = pPosition;
	m_pLight->setup(pPosition, color, intencity);
	SGLT_LIGHT_AGGREGATE->addLight(m_pLight);
}




