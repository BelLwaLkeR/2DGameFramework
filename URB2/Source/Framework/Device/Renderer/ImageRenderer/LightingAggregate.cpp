#include "LightingAggregate.h"
#include <Source/Utility/Math/VectorMath.h>

framework::LightAggregate::LightAggregate(){
	setAmbientLight({});
	m_pLightList.clearAllTask();
}

framework::LightAggregate::~LightAggregate(){
	int a = 0;
}

std::list<util::WeakPtr<framework::Light>> framework::LightAggregate::getAffectLight(const util::Vector2 &position){
	std::list<util::WeakPtr<framework::Light>> lightList;
	for (const auto& light : m_pLightList.getTaskList()) {
		if (util::VectorMath::length2(*light->pPosition.lock() - position) <= std::pow(light->intencity, 2)) {
			lightList.emplace_back(light);
		}
	}
	if (lightList.size() > 0) { return lightList; }
	return std::list<util::WeakPtr<framework::Light>>();
}

util::WeakPtr<util::Color> framework::LightAggregate::setAmbientLight(const util::Color & color){
	m_pAmbientColor = util::makeShared<util::Color>(color);
	return m_pAmbientColor;
}

util::WeakPtr<util::Color> framework::LightAggregate::getAmbientLight(){
	return m_pAmbientColor;
}

void framework::LightAggregate::reloadLight(){
	m_pLightList.refleshTask();
}

void framework::LightAggregate::addLight(util::WeakPtr<Light> light){
	m_pLightList.addTask(light);
}

void framework::LightAggregate::removeLight(util::WeakPtr<Light> light){
	m_pLightList.removeTask(light);
}













