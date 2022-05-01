#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string filePath = "words.txt";
vector<string> words;

string secretWord;
vector<char> lettersBids;
bool isRunning = true;
int maxBidsWrong = 10;

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

void printSecretWord()
{
  for (char letter : secretWord)
  {
    if (thisBidIsGone(letter))
    {
      cout << letter << "";
    }
    else
    {
      cout << "_";
    }
  }
  cout << endl;
}

void checkingRules()
{
  int bidsWrong = 0;
  int hits = 0;
  int hitsNeeded = secretWord.size();

  for (char letter : secretWord)
  {
    if (thisBidIsGone(letter))
    {
      hits++;
    }
  }

  for (char letter : lettersBids)
  {
    if (!thisBidIsRight(letter))
    {
      bidsWrong++;
    }
  }

  if (hits == hitsNeeded)
  {
    cout << "You win the game!!";
    isRunning = false;
  }

  if (bidsWrong == maxBidsWrong)
  {
    cout << "You lose the game. The Secret Word is " << secretWord << endl;
    isRunning = false;
  }
}

void game()
{
  cout << "You need to guess the word" << endl;
  while (isRunning)
  {
    printSecretWord();
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
    checkingRules();
  }
}

void readFile()
{
  ifstream file;
  file.open(filePath);

  if (file.is_open())
  {
    int numWords;
    file >> numWords;

    for (int i = 0; i < numWords; i++)
    {
      string word;
      file >> word;
      words.push_back(word);
    }
    file.close();
  }
  else
  {
    cout << "Error in open file with words... Closing game.....";
    isRunning = false;
  }
}

void introduction()
{
  cout << "*********************************" << endl;
  cout << "**** Welcome to Hangman Game ****" << endl;
  cout << "*********************************" << endl;
  readFile();

  srand(time(NULL));
  int randomIndex = rand() % words.size();
  secretWord = words[randomIndex];
}

int main()
{
  introduction();
  game();
}
