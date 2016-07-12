#pragma once
#include <vector>

namespace util {
	class CSVLoader
	{
	public:
		CSVLoader();
		~CSVLoader();
		
		static std::vector<std::vector<std::string>> load(const std::string& filePath, bool ignoreFirstLine = true);
	private:

	};
}