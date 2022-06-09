#pragma once
#include <string>
#include "Account.h"
#include "Holder.h"

class StudentAccount : public Account
{
public:
	StudentAccount(Holder holder, std::string accountNumber);
	~StudentAccount();
};

