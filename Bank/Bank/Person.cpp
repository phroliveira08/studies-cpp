#include "Person.h"
#include <string>

Person::Person(std::string name): name(name)
{}

Person::Person(char * name): name(name)
{}

std::string Person::getName() const {
	return name;
}