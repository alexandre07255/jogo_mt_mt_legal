#include "Save.h"
#include <iostream>
#include <fstream>

nlohmann::json Save::readJson(std::string path){
	std::fstream jsonFileStream(path);

	nlohmann::json jsonData;

	try {
		jsonData = nlohmann::json::parse(jsonFileStream);
	}
	catch (nlohmann::json::parse_error& ex)
	{
		std::cerr << "parse error at byte " << ex.byte << std::endl;
	}

	return jsonData;
}

void Save::writejson(std::string path, nlohmann::json source) {
	std::ofstream jsonOut(path);

	jsonOut << source;
}

Save::Save() {
}

Save::~Save() {
}