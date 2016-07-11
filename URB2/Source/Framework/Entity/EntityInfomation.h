#pragma once

#include <string>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Hash.h>

namespace framework {
	struct EntityInfomation {
		std::string		name;
		util::Hash		tag;
		unsigned int	id;
		util::Vector2	position;
	};

}