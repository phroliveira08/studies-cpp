#pragma once
#include <string>
#include "Holder.h"

class Account {

private:
	static int numberAccounts;

public:
	static int getNumberAccounts();

protected:
	Holder holder;
	std::string accountNumber;
	float balance;
	float tax;

public:
	Account(Holder holder, std::string accountNumber, float tax);
	~Account();
	void deposit(float value);
	void withdraw(float value);
	void transferTo(Account &accountTo, float value);
	float getBalance() const;
	std::string getAccountNumber() const;
	std::string getProfileName() const;
};
