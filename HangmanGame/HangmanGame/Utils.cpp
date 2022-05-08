#include "Utils.hpp"

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

bool ThisBidIsGone(char letterBid, std::vector<char> lettersBids)
{
  bool result = LookingLetter(letterBid, lettersBids);
  return result;
}

bool ThisBidIsRight(char letterBid, std::string secretWord)
{
  bool result = LookingLetter(letterBid, secretWord);
  return result;
}