#include "CSVLoad.h"

CSVLoad::CSVLoad(){
}

CSVLoad::~CSVLoad(){
}

const std::vector<std::string> CSVLoad::loadCSVOneLineString(const std::string & path, char delimiter){
	return std::vector<std::string>();
}

const std::vector<int> CSVLoad::loadCSVOneLineInt(const std::string & path, char delimiter){
	return std::vector<int>();
}

const std::vector<float> CSVLoad::loadCSVOneLineFloat(const std::string & path, char delimiter){
	return std::vector<float>();
}

const std::vector<std::vector<std::string>> CSVLoad::loadCSVMultiLineString(const std::string & path, char delimiter){
	return std::vector<std::vector<std::string>>();
}

const std::vector<std::vector<int>> CSVLoad::loadCSVMultiLineInt(const std::string & path, char delimiter){
	return std::vector<std::vector<int>>();
}

const std::vector<std::vector<float>> CSVLoad::loadCSVMultiLineFloat(const std::string & path, char delimiter){
	return std::vector<std::vector<float>>();
}
