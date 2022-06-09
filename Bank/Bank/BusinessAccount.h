#pragma once
#include "Account.h"
#include "Holder.h"
#include <string>

class BusinessAccount : public Account
{
public:
	BusinessAccount(Holder holder, std::string accountNumber);
	~BusinessAccount();
};

