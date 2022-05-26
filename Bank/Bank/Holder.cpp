#include "Holder.h"

Holder::Holder(std::string name):name(name)
{}

Holder::Holder(const char* name): name(name)
{}

std::string Holder::getName() const{
	return name;
}
