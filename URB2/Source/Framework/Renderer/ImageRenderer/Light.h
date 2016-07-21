#pragma once

#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Color.h>

namespace framework {
	struct Light
	{
		util::WeakPtr<util::Vector2>	pPosition;
		util::Color		color;
		float			intencity;

		Light() {}
		Light(util::WeakPtr<util::Vector2> pPosition) {
			this->pPosition = pPosition;
		}
		Light(util::WeakPtr<util::Vector2> pPosition, const util::Color& color, float intencity) {
			this->pPosition	= pPosition;
			this->color		= color;
			this->intencity	= intencity;
		}

		void setup(util::WeakPtr<util::Vector2> pPosition, const util::Color& color, float intencity) {
			this->pPosition	= pPosition;
			this->color		= color;
			this->intencity	= intencity;
		}

	};
}