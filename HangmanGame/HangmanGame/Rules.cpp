#include <iostream>
#include <vector>
#include <string>
#include "Utils.hpp"
#include "File.hpp"

extern std::vector<std::string> words;
extern std::string secretWord;
extern std::vector<char> lettersBids;
extern bool isRunning;
extern int maxBidsWrong;

void CheckingRules()
{
  int bidsWrong = 0;
  int hits = 0;
  int hitsNeeded = secretWord.size();

  for (char letter : secretWord)
  {
    if (ThisBidIsGone(letter))
    {
      hits++;
    }
  }

  for (char letter : lettersBids)
  {
    if (!ThisBidIsRight(letter))
    {
      bidsWrong++;
    }
  }

  if (hits == hitsNeeded)
  {
    std::cout << "You win the game!!" << std::endl;
    std::cout << "Do you want to add a word to the database? Y - Yes / N - No" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
      std::cout << "Type a word:" << std::endl;
      std::string word;
      std::cin >> word;
      words.push_back(word);
      WriteFile();
    }
    isRunning = false;
  }

  if (bidsWrong == maxBidsWrong)
  {
    std::cout << "You lose the game. The Secret Word is " << secretWord << std::endl;
    isRunning = false;
  }
}