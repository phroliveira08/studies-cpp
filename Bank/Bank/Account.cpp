#include <stdexcept>
#include <iostream>
#include "Account.h"
#include "Holder.h"

int Account::numberAccounts = 0;

Account::Account(Holder holder, std::string accountNumber, float tax):
	holder(holder),
	accountNumber(accountNumber),
	balance(0),
	tax(tax)
{
	numberAccounts++;
}

Account::~Account() {
	numberAccounts--;
}

void Account::deposit(float value) {
	if (value <= 0) {
		throw std::invalid_argument("It isn't possible to deposit negative values");
	}
	balance += value;
}

void Account::withdraw(float value) {
	if (value <= 0) {
		throw std::invalid_argument("It isn't possible to withdraw negative values");
	}

	float taxValue = value * tax;
	float valueToWithdraw = value + taxValue;

	if (valueToWithdraw > balance) {
		throw std::invalid_argument("You don't have enough money");
	}
	
	balance -= valueToWithdraw;
}

void Account::transferTo(Account &accountTo, float value) {
	try {
		this->withdraw(value);
		accountTo.deposit(value);
	}catch(std::invalid_argument& e){
		std::cout << e.what() << std::endl;
	}
}

float Account::getBalance() const {
	std::cout << balance << std::endl;
	return balance;
}

std::string Account::getAccountNumber() const {
	return accountNumber;
}

std::string Account::getProfileName() const {
	return holder.getName();
}

int Account::getNumberAccounts() {
	return numberAccounts;
}