#include <iostream>
#include "Utils.hpp"
#include "Rules.hpp"
#include "File.hpp"

bool CheckingRules(const std::string& secretWord, const int& maxBidsWrong, const std::vector<char>& lettersBids, const std::string& filePath, std::vector<std::string>& words)
{
  int bidsWrong = 0;
  int hits = 0;
  int hitsNeeded = secretWord.size();
  bool continueRunning = true;

  for (char letter : secretWord)
  {
    if (ThisBidIsGone(letter, lettersBids))
    {
      hits++;
    }
  }

  for (char letter : lettersBids)
  {
    if (!ThisBidIsRight(letter, secretWord))
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
      continueRunning = WriteFile(filePath, words);
    }
    continueRunning = false;
  }

  if (bidsWrong == maxBidsWrong)
  {
    std::cout << "You lose the game. The Secret Word is " << secretWord << std::endl;
    continueRunning = false;
  }

  return continueRunning;
}