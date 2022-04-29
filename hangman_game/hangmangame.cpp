#include <iostream>
#include <vector>
using namespace std;

string secretWord = "TESTE";
std::vector<int> hits;
bool isRunning = true;

bool thisBidIsGone(int indexBid)
{
  int lengthHits = hits.size();

  for (int i = 0; i < lengthHits; i++)
  {
    int index = hits[i];
    if (index == indexBid)
    {
      return true;
    }
  }

  return false;
}

bool thisBidIsRight(char letterBid)
{
  int lengthWord = secretWord.size();

  for (int i = 0; i < lengthWord; i++)
  {
    char letter = secretWord[i];
    if (letter == letterBid)
    {
      bool isGone = thisBidIsGone(i);
      if (!isGone)
      {
        hits.push_back(i);
        return true;
      }
    }
  }

  return false;
}

void game()
{
  cout << "You need to guess the word" << endl;
  while (isRunning)
  {
    char letterBid;
    cin >> letterBid;
    bool checkingBid = true;
    bool isRight = false;
    int numLettersRight = 0;
    while (checkingBid)
    {
      checkingBid = thisBidIsRight(letterBid);
      if (checkingBid)
      {
        isRight = true;
        numLettersRight++;
      }
    }
    if (isRight)
    {
      cout << "You hit the bid!!";
    }
    else
    {
      cout << "You miss the bid :(";
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
