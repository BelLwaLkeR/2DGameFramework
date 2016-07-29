#pragma once

#include <Source/Framework/Component/LightComponent.h>
#include <Source/Framework/Component/UpdateComponent.h>

/**
* @class		WhiteLight
* @namespace	component
* @brief		白いポイントライトを持つ
* @author		大森 健司
*/

namespace component {
	class WhiteLight: public framework::UpdateComponent{
	public:
		WhiteLight();
		~WhiteLight();
		void setup(util::WeakPtr<framework::Entity> pEntity, util::WeakPtr<util::Vector2> pPosition) override;
		void update() override;
	private:
		framework::LightComponent	m_LightComponent;
	};
}



