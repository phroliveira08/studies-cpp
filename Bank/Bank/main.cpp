#include "BusinessAccount.h"
#include "StudentAccount.h"
#include "Employee.h"
#include <iostream>

using namespace std;

int main() {
	BusinessAccount account1(string("Nome1"), "100");
	StudentAccount account2("Nome2", "101");
	BusinessAccount account3("Nome3", "102");
	StudentAccount account4("Nome4", "103");
	Employee employee1("Func1", 1800.00);

	StudentAccount* account5 = new StudentAccount("Nome5", "103"); //HEAP
	
	account1.deposit(1000);
	account1.withdraw(200);
	account1.getBalance();
	account1.transferTo(account2, 140);
	account2.transferTo(account1, 40);
	account1.transferTo(account3, 20);
	account1.transferTo(account4, 25);
	account5->deposit(1000);
	account5->withdraw(200);

	account1.getBalance();
	account2.getBalance();
	account3.getBalance();
	account4.getBalance();
	account5->getBalance();

	cout << "Num: " << Account::getNumberAccounts() << endl;
}