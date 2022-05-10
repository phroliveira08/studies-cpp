#pragma once
#include <string>
#include <vector>

template <typename T>
bool LookingLetter(const char& letterToCheck,const  T& word);
bool ThisBidIsGone(const char& letterBid, const std::vector<char>& lettersBids);
bool ThisBidIsRight(const char& letterBid, const std::string& secretWord);