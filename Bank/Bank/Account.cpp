#include <stdexcept>
#include <iostream>
#include "Account.h"

Account::Account(std::string nameProfile, std::string accountNumber): 
	nameProfile(nameProfile),
	accountNumber(accountNumber),
	balance(0)
{}

void Account::deposit(float valueToDeposit) {
	if (valueToDeposit <= 0) {
		throw std::invalid_argument("It isn't possible to deposit negative values");
	}
	balance += valueToDeposit;
}

void Account::withdraw(float valueToWithdraw) {
	if (valueToWithdraw > balance) {
		throw std::invalid_argument("You don't have enough money");
	}
	if (valueToWithdraw <= 0) {
		throw std::invalid_argument("It isn't possible to withdraw negative values");
	}
	balance -= valueToWithdraw;
}

void Account::transferTo(Account &accountTo, float valueTo) {
	try {
		this->withdraw(valueTo);
		accountTo.deposit(valueTo);
	}catch(std::invalid_argument& e){
		std::cout << e.what() << std::endl;
	}
}

float Account::getBalance() const {
	return balance;
}

std::string Account::getNameProfile() const {
	return nameProfile;
}

void Account::changeNameProfile(std::string newName)
{
	this->nameProfile = newName;
}

std::string Account::getAccountNumber() const {
	return accountNumber;
}