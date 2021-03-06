#pragma once
#include <string>
#include <vector>

/**
* @class		StringEditor
* @namespace	util
* @brief		stringถ๑๐าWท้ึNX
* @author		ๅX i
*/

namespace util {
	class StringEditor
	{
	public:
		StringEditor()	{}
		~StringEditor()	{}

		template<typename T>
		static std::string getClassName();
		static std::vector<std::string> split(const std::string& string, char splitSimbole);

	};

	template<typename T>
	inline std::string StringEditor::getClassName(){
		std::vector<std::string>& strVector = split(typeid(T).name(), ':');
		return strVector[strVector.size()-1];
	}
}