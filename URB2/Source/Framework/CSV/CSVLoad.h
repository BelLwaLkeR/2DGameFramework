#pragma once

#include <vector>
#include <string>

class CSVLoad
{
public:
	CSVLoad();
	~CSVLoad();
	const std::vector<std::string>	loadCSVOneLineString	(const std::string& path, char delimiter = ',');
	const std::vector<int>			loadCSVOneLineInt		(const std::string& path, char delimiter = ',');
	const std::vector<float>		loadCSVOneLineFloat		(const std::string& path, char delimiter = ',');
	const std::vector<std::vector<std::string>>	loadCSVMultiLineString	(const std::string& path, char delimiter = ',');
	const std::vector<std::vector<int>>			loadCSVMultiLineInt		(const std::string& path, char delimiter = ',');
	const std::vector<std::vector<float>>		loadCSVMultiLineFloat	(const std::string& path, char delimiter = ',');
private:

};

