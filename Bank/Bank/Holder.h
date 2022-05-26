#pragma once
#include <string>

class Holder {
private:
	std::string name;

public:
	Holder(std::string name);
	Holder(const char* name);
	std::string getName() const;
};
