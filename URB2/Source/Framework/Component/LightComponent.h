#pragma once
#include <Source/Framework/Component/UpdateComponent.h>
#include <Source/Utility/Type/Color.h>

namespace framework{
	struct Light;
	class LightComponent: framework::UpdateComponent{
	public:
		LightComponent();
		LightComponent(const util::Color& color, float intencity);
		~LightComponent();



	protected:
		util::SharedPtr<Light> m_pLight;

	private:

	};

}