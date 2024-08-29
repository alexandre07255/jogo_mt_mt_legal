#pragma once
#include "json.hpp"
#include <string>

class Save
{
protected:
	nlohmann::json saveJson;
public:
	Save();
	virtual ~Save();

	static nlohmann::json readJson(std::string path);
	void writejson(std::string path, nlohmann::json source);
};

