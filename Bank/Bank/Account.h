#pragma once
#include <string>

class Account {
private:
	std::string nameProfile = "Teste";
	std::string accountNumber;
	float balance = 0;

public:
	void deposit(float valueToDeposit);
	void withdraw(float valueToWithdraw);
	float getBalance() const;
	std::string getNameProfile() const;
};
