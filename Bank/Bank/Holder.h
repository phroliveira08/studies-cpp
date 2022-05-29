#pragma once
#include "Person.h"
#include <string>

class Holder : public Person
{
public:
	Holder(std::string name);
	Holder(const char* name);
};
