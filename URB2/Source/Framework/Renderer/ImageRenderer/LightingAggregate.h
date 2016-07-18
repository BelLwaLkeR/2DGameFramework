#pragma once
#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Singleton.h>
#include <Source/Framework/Renderer/ImageRenderer/Light.h>

#define SGLT_LIGHTINGAGGREGATE framework::LightAggregate::getInstance()

namespace framework {
	class LightAggregate :public util::Singleton<LightAggregate>
	{
	public:
		LightAggregate() {}
		~LightAggregate(){}

		std::list<util::WeakPtr<Light>> getAffectLight(const util::Vector2& position);
		void addLight(util::WeakPtr<Light> light);
		void removeLight(util::WeakPtr<Light> light);

	private:
		std::list<util::WeakPtr<Light>>	m_pLightList;
	};
}