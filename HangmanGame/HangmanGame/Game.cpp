#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Utils.hpp"
#include "File.hpp"
#include "Game.hpp"
#include "Rules.hpp"
using namespace std;

string filePath = "words.txt";
vector<string> words;

string secretWord;
vector<char> lettersBids;
bool isRunning = true;
int maxBidsWrong = 10;

void Introduction()
{
  isRunning = ReadFile(filePath, &words);

  srand(time(NULL));
  int randomIndex = rand() % words.size();
  secretWord = words[randomIndex];
}

void PrintSecretWord()
{
  for (char letter : secretWord)
  {
    if (ThisBidIsGone(letter, lettersBids))
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

void Game()
{
  cout << "You need to guess the word" << endl;
  while (isRunning)
  {
    PrintSecretWord();
    char letterBid;
    cin >> letterBid;
    bool isGone = ThisBidIsGone(letterBid, lettersBids);
    if (isGone)
    {
      cout << "That letter is gone, try other letter" << endl;
    }
    else
    {
      lettersBids.push_back(letterBid);
      bool isRight = ThisBidIsRight(letterBid, secretWord);
      if (isRight)
      {
        cout << "You hit the bid!!" << endl;
      }
      else
      {
        cout << "You miss the bid :(" << endl;
      }
    }
    isRunning = CheckingRules(secretWord, maxBidsWrong, lettersBids, filePath, &words);
  }
}