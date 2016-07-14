#pragma once

#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Color.h>

namespace framework {
	struct Light
	{
		util::Vector2	position;
		util::Color		color;
		float			intencity;

		Light() {}
		Light(const util::Vector2& position, const util::Color& color, float intencity) {
			this->position	= position;
			this->color		= color;
			this->intencity	= intencity;
		}
	};
}