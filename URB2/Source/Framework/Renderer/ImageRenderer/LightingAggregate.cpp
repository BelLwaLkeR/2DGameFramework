#include "LightingAggregate.h"
#include <Source/Utility/Math/VectorMath.h>

std::list<util::WeakPtr<framework::Light>> framework::LightAggregate::getAffectLight(const util::Vector2 &position){
	std::list<util::WeakPtr<framework::Light>> lightList;
	for (const auto& light : m_pLightList) {
		if (util::VectorMath::length2(*light->pPosition.lock() - position) <= std::pow(light->intencity, 2)) {
			lightList.emplace_back(light);
		}
	}
	return lightList;
}

void framework::LightAggregate::addLight(util::WeakPtr<Light> light){
	m_pLightList.emplace_back(light);
}

void framework::LightAggregate::removeLight(util::WeakPtr<Light> light){
	m_pLightList.remove(light);
}
