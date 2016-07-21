#pragma once
#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Singleton.h>
#include <Source/Framework/Renderer/ImageRenderer/Light.h>

#define SGLT_LIGHT_AGGREGATE framework::LightAggregate::getInstance()

namespace framework {
	class LightAggregate :public util::Singleton<LightAggregate>
	{
	public:
		LightAggregate();
		~LightAggregate();

		std::list<util::WeakPtr<Light>> getAffectLight(const util::Vector2& position);
		util::WeakPtr<util::Color> setAmbientLight(const util::Color& color);
		util::WeakPtr<util::Color> getAmbientLight();
		void addLight(util::WeakPtr<Light> light);
		void removeLight(util::WeakPtr<Light> light);

	private:
		std::list<util::WeakPtr<Light>>	m_pLightList;
		util::SharedPtr<util::Color>	m_pAmbientColor;
	};
}