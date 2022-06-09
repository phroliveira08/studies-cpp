#include "StudentAccount.h"

StudentAccount::StudentAccount(Holder holder, std::string accountNumber):
	Account(holder, accountNumber, 0.01)
{}

StudentAccount::~StudentAccount() {}

