#pragma once
#include <string>

class Account {

private:
	static int numberAccounts;

public:
	static int getNumberAccounts();

private:
	std::string nameProfile;
	std::string accountNumber;
	float balance;

public:
	Account(std::string nameProfile, std::string accountNumber);
	~Account();
	void deposit(float valueToDeposit);
	void withdraw(float valueToWithdraw);
	void transferTo(Account &accountTo, float valueTo);
	void changeNameProfile(std::string newName);
	float getBalance() const;
	std::string getNameProfile() const;
	std::string getAccountNumber() const;
};
