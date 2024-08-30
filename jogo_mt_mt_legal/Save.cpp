#include "Save.h"
#include <iostream>
#include <fstream>

nlohmann::json Save::readJson(std::string path){
	std::fstream jsonFileStream(path, std::ios::in);

	nlohmann::json jsonData;

	try {
		jsonData = nlohmann::json::parse(jsonFileStream);
	}
	catch (nlohmann::json::parse_error& ex)
	{
		std::cerr << "parse error at byte " << ex.byte << std::endl;
	}
	jsonFileStream.close();
	return jsonData;
}

void Save::writejson(std::string path, nlohmann::json source) {
	std::ofstream jsonOut(path, std::ios::out);

	jsonOut << source;
	//auxilio do chatGPT
	jsonOut.close();
}

Save::Save() {
}

Save::~Save() {
}