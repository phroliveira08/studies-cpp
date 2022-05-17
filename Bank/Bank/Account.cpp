#include "Account.h"

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

float Account::getBalance() const {
	return balance;
}

std::string Account::getNameProfile() const {
	return nameProfile;
}