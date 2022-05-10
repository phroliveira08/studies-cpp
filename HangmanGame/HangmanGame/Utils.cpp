#include "Utils.hpp"

template <typename T>
bool LookingLetter(const char& letterToCheck, const T& word)
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

bool ThisBidIsGone(const char& letterBid, const std::vector<char>& lettersBids)
{
  bool result = LookingLetter(letterBid, lettersBids);
  return result;
}

bool ThisBidIsRight(const char& letterBid, const std::string& secretWord)
{
  bool result = LookingLetter(letterBid, secretWord);
  return result;
}