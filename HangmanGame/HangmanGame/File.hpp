#pragma once
#include <vector>
#include <string>

bool ReadFile(std::string filePath, std::vector<std::string>* words);
bool WriteFile(std::string filePath, std::vector<std::string> words);