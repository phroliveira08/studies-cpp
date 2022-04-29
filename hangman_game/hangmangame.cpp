#include <iostream>
#include <vector>
using namespace std;

string secretWord = "TESTE";
vector<char> lettersBids;
bool isRunning = true;

template <typename T>
bool lookingLetter(char letterToCheck, T word)
{
  for (char letter : word)
  {
    if (letter == letterToCheck)
    {
      return true;
    }
  }

  return false;
}

bool thisBidIsGone(char letterBid)
{
  bool result = lookingLetter(letterBid, lettersBids);
  return result;
}

bool thisBidIsRight(char letterBid)
{
  bool result = lookingLetter(letterBid, secretWord);
  return result;
}

void game()
{
  cout << "You need to guess the word" << endl;
  while (isRunning)
  {
    char letterBid;
    cin >> letterBid;
    bool isGone = thisBidIsGone(letterBid);
    if (isGone)
    {
      cout << "That letter is gone, try other letter" << endl;
    }
    else
    {
      lettersBids.push_back(letterBid);
      bool isRight = thisBidIsRight(letterBid);
      if (isRight)
      {
        cout << "You hit the bid!!" << endl;
      }
      else
      {
        cout << "You miss the bid :(" << endl;
      }
    }
  }
}

int main()
{
  cout << "*********************************" << endl;
  cout << "**** Welcome to Hangman Game ****" << endl;
  cout << "*********************************" << endl;

  game();
}
