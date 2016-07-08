#pragma once

#include <string>
#include <Source/Utility/Type/Vector2.h>
#include <Source/Utility/Type/Hash.h>

namespace framework {
	struct EntityInfomation {
		std::string		m_Name;
		util::Hash		m_Tag;
		unsigned int	m_Id;
		util::Vector2	m_Position;
	};

}