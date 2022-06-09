#include "BusinessAccount.h"


BusinessAccount::BusinessAccount(Holder holder, std::string accountNumber):
	Account(holder, accountNumber, 0.05)
{}

BusinessAccount::~BusinessAccount() {}