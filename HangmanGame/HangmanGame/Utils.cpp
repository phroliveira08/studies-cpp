#include <vector>
#include <string>
#include "Utils.hpp"

extern std::string secretWord;
extern std::vector<char> lettersBids;

template <typename T>
bool LookingLetter(char letterToCheck, T word)
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

bool ThisBidIsGone(char letterBid)
{
  bool result = LookingLetter(letterBid, lettersBids);
  return result;
}

bool ThisBidIsRight(char letterBid)
{
  bool result = LookingLetter(letterBid, secretWord);
  return result;
}