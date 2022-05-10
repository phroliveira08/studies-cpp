#pragma once
#include <vector>
#include <string>

bool ReadFile(const std::string& filePath, std::vector<std::string>& words);
bool WriteFile(const std::string& filePath, std::vector<std::string>& words);