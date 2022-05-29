#include "Account.h"
#include "Employee.h"
#include <iostream>

using namespace std;

void showBalance(const Account* account) {
	cout << "Balance from " << account->getProfileName() << " is " << account->getBalance() << endl;
}
void showBalance(const Account& account) {
	cout << "Balance from " << account.getProfileName() << " is " << account.getBalance() << endl;
}

int main() {
	Account account1(string("Nome1"), "100");
	Account account2("Nome2", "101");
	Account account3("Nome3", "102");
	Account account4("Nome4", "103");
	Employee employee1("Func1", 1800.00);

	Account* account5 = new Account("Nome5", "103"); //HEAP
	
	account1.deposit(800);
	account1.withdraw(200);
	account1.transferTo(account2, 140);
	account2.transferTo(account1, 40);
	account1.transferTo(account3, 20);
	account1.transferTo(account4, 25);
	account5->deposit(1000);

	showBalance(account1);
	showBalance(account2);
	showBalance(account3);
	showBalance(account4);
	showBalance(account5);

	cout << "Num: " << Account::getNumberAccounts() << endl;
}