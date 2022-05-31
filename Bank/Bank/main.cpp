#include "Account.h"
#include "Employee.h"
#include <iostream>

using namespace std;

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

	account1.getBalance();
	account2.getBalance();
	account3.getBalance();
	account4.getBalance();
	account5->getBalance();

	cout << "Num: " << Account::getNumberAccounts() << endl;
}