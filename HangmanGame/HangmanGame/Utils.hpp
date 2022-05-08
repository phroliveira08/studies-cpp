#pragma once
#include <string>
#include <vector>

template <typename T>
bool LookingLetter(char letterToCheck, T word);
bool ThisBidIsGone(char letterBid, std::vector<char> lettersBids);
bool ThisBidIsRight(char letterBid, std::string secretWord);