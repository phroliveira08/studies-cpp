#include "Account.h"
#include <iostream>

using namespace std;

void showBalance(const Account& account) {
	cout << "Balance from " << account.getNameProfile() << " is " << account.getBalance() << endl;
}

int main() {
	Account account1("Nome1", "100");
	Account account2("Nome2", "101");
	
	account1.deposit(500);
	account1.withdraw(200);
	account1.transferTo(account2, 140);
	account2.transferTo(account1, 40);

	showBalance(account1);
	showBalance(account2);
}