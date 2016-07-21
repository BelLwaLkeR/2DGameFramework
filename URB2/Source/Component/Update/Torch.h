#pragma once
#include <Source/Framework/Component/UpdateComponent.h>
#include <Source/Framework/Component/LightComponent.h>

namespace component {
	class Torch: public framework::UpdateComponent{
	public:
		Torch();
		~Torch();
		void setup(util::WeakPtr<framework::Entity> pEntity, util::WeakPtr<util::Vector2> pPosition) override;
		void update() override;
	private:
		framework::LightComponent	m_LightComponent;

	};
}