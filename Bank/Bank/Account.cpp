#include "Account.h"

Account::Account(std::string nameProfile, std::string accountNumber): 
	nameProfile(nameProfile),
	accountNumber(accountNumber),
	balance(0)
{}

void Account::deposit(float valueToDeposit) {
	if (valueToDeposit <= 0) {
		return;
	}
	balance += valueToDeposit;
}

void Account::withdraw(float valueToWithdraw) {
	if (valueToWithdraw > balance) {
		return;
	}
	if (valueToWithdraw <= 0) {
		return;
	}
	balance -= valueToWithdraw;
}

void Account::transferTo(Account &accountTo, float valueTo) {
	this->withdraw(valueTo);
	accountTo.deposit(valueTo);
}

float Account::getBalance() const {
	return balance;
}

std::string Account::getNameProfile() const {
	return nameProfile;
}