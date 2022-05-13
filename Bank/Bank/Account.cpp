#include <iostream>
#include "Account.h"

void Account::deposit(float valueToDeposit) {
	balance += valueToDeposit;
	std::cout << "(Deposit)New Balance: " << balance << std::endl;
}

void Account::withdraw(float valueToWithdraw) {
	balance -= valueToWithdraw;
	std::cout << "(Withdraw)New Balance: " << balance << std::endl;
}