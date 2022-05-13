#pragma once
#include <string>

class Account {
private:
	std::string nameProfile;
	std::string accountNumber;
	float balance = 0;

public:
	void deposit(float valueToDeposit);
	void withdraw(float valueToWithdraw);
};
