#include <iostream>
using namespace std;

int secretNumber = 10;
int isRunning = true;

void game()
{
  int guestNumber;
  cout << "Try to guess the secret number" << endl;
  while (isRunning)
  {
    cin >> guestNumber;
    bool isValid = guestNumber == secretNumber;
    bool isHigher = guestNumber > secretNumber;
    if (isValid)
    {
      cout << "You win!" << endl;
      isRunning = false;
    }
    else if (isHigher)
    {
      cout << "This number is higher than secret number" << endl;
    }
    else
    {
      cout << "This number is less than secret number" << endl;
    }
  }
}

int main()
{
  cout << "**************************************" << endl;
  cout << "**** Welcome to the Guessing Game ****" << endl;
  cout << "**************************************" << endl;
  game();
}
