#include "Account.h"
#include <iostream>

using namespace std;

void showBalance(const Account& account) {
	cout << "Balance from" << account.getNameProfile() << " is " << account.getBalance() << endl;
}

int main() {
	Account account1;
	
	account1.deposit(500);
	account1.withdraw(200);

	showBalance(account1);
}