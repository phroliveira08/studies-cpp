#pragma once
#include <string>
#include <vector>

bool CheckingRules(const std::string& secretWord, const int& maxBidsWrong, const std::vector<char>& lettersBids, const std::string& filePath, std::vector<std::string>& words);