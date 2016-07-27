#pragma once

#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Color.h>

/**
* @class		LightComponent
* @namespace	framework
* @brief		���C�g�R���|�[�l���g�p�N���X
* @author		��X ���i
*/


namespace framework{
	struct Light;
	class LightComponent{
	public:
		LightComponent();
		~LightComponent();

		void setup(util::WeakPtr<util::Vector2> pPosition, const util::Color& color, float intencity);
		void changeColor(const util::Color& color);
		void changeIntencity(float intencity);

	private:
		util::SharedPtr<Light>			m_pLight;
		util::WeakPtr<util::Vector2>	m_pPosition;

	};

}