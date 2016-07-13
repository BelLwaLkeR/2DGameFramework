#include "StringEditor.h"
#include <iostream>


std::vector<std::string> util::StringEditor::split(const std::string & string, char splitSimbole){
	std::vector<std::string> exportStr;
	std::string tmpStr;

	for (char c : string) {
		if (c != splitSimbole) {
			tmpStr += c;
			continue;
		}
		exportStr.emplace_back(tmpStr);
		tmpStr.clear();
	}
	if (!tmpStr.empty()) { exportStr.emplace_back(tmpStr); }

	return exportStr;
}
