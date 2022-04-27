#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isRunning = true;

const int EASY = 15;
const int MEDIUM = 10;
const int HARD = 5;

double score = 1000.0;
int attempts = 0;
int limitAttempts = 15;

void setDifficulty()
{
  cout << "Choose a difficulty, E (Easy)/M (Medium)/H (Hard)" << endl;
  char gameDifficulty;
  cin >> gameDifficulty;
  switch (gameDifficulty)
  {
  case 'E':
    limitAttempts = EASY;
    break;
  case 'M':
    limitAttempts = MEDIUM;
    break;
  case 'H':
    limitAttempts = HARD;
    break;
  default:
    limitAttempts = EASY;
    cout << "It mode doesn't exist, set default mode Easy" << endl;
    break;
  }
}

void rulesToEndGame()
{
  int fixedLimitAttempts = limitAttempts + 1;
  if (limitAttempts == attempts)
  {
    isRunning = false;
    cout << "You lost the game because the attempt limit are reached, try again in other difficulty mode" << endl;
  }
}

void game()
{
  srand(time(NULL));
  const int SECRET_NUMBER = rand() % 100;
  cout << SECRET_NUMBER << endl;
  int guestNumber;
  setDifficulty();
  cout << "Try to guess the secret number between 0 and 99" << endl;
  while (isRunning)
  {
    attempts++;
    cout << "Attempt: " << attempts << endl;
    cin >> guestNumber;
    bool isValid = guestNumber == SECRET_NUMBER;
    bool isHigher = guestNumber > SECRET_NUMBER;
    score = score - abs(SECRET_NUMBER - guestNumber) / 2.0;
    if (isValid)
    {
      cout << "You win in the " << attempts << " attempt!" << endl;
      cout.precision(2);
      cout << fixed;
      cout << "Your score: " << score << endl;
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
    rulesToEndGame();
  }
}

int main()
{
  cout << "**************************************" << endl;
  cout << "**** Welcome to the Guessing Game ****" << endl;
  cout << "**************************************" << endl;
  game();
}
