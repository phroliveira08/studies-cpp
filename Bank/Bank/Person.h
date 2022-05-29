#pragma once
#include <string>

class Person
{
private:
	std::string name;

public:
	Person(std::string name);
	Person(char* name);
	std::string getName() const;
};

