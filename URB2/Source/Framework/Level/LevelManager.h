#pragma once

#include <map>
#include <string>
#include <Source/Framework/Level/ILevel.h>
#include <Source/Utility/StringEditor.h>
#include <Source/Utility/Singleton.h>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/Type/Color.h>

namespace framework {
	class LevelManager: public util::Singleton<LevelManager>
	{
	public:
		LevelManager() {}
		~LevelManager() {}
		void addLevel();
		const util::Color& getAmbientColor();

	private:
		std::map<std::string, util::SharedPtr<ILevel>> m_LevelMap;
		util::Color m_AmbientColor;

	};
}

