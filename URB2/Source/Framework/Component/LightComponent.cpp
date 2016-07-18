#include "LightComponent.h"
#include <Source/Framework/Renderer/ImageRenderer/LightingAggregate.h>
#include <Source/Framework/Renderer/ImageRenderer/Light.h>

framework::LightComponent::LightComponent(){
	m_pLight = util::makeShared<Light>();
	SGLT_LIGHTINGAGGREGATE->addLight(m_pLight);
}

framework::LightComponent::LightComponent(const util::Color & color, float intencity){
	m_pLight			= util::makeShared<Light>(m_pPosition, color, intencity);
	SGLT_LIGHTINGAGGREGATE->addLight(m_pLight);
}

framework::LightComponent::~LightComponent(){
	SGLT_LIGHTINGAGGREGATE->removeLight(m_pLight);
}
