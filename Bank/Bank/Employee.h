#pragma once
#include "Person.h"
#include <string>

class Employee : public Person
{
private:
	float salary;

public:
	Employee(std::string name, float salary);
};

