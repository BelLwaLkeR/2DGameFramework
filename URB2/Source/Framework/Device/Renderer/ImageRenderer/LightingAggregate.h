#pragma once
#include <list>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Singleton.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/Light.h>

/**
* @class		LightAggreage
* @inheritance	Singleton<LightAggregate>
* @namespace	framework
* @brief		Light‚Ìî•ñ‚ğ‚Ğ‚Æ‚Ü‚Æ‚ß‚É‚µ‚½ƒNƒ‰ƒX
* @author		‘åX Œ’i
*/
#include <Source/Utility/TaskList.h>

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
		void reloadLight();
		void addLight(util::WeakPtr<Light> light);
		void removeLight(util::WeakPtr<Light> light);

	private:
		util::TaskList<Light>			m_pLightList;
		util::SharedPtr<util::Color>	m_pAmbientColor;
	};
}