#pragma once
#include <string>

class Account {
private:
	std::string nameProfile;
	std::string accountNumber;
	float balance;

public:
	Account(std::string nameProfile, std::string accountNumber);
	void deposit(float valueToDeposit);
	void withdraw(float valueToWithdraw);
	void transferTo(Account &accountTo, float valueTo);
	float getBalance() const;
	std::string getNameProfile() const;
};
