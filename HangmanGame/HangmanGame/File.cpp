#include <fstream>
#include <iostream>
#include "File.hpp"

bool ReadFile(std::string& filePath, std::vector<std::string>& words)
{
  std::ifstream file;
  file.open(filePath);
  bool continueRunning = true;

  if (file.is_open())
  {
    int numWords;
    file >> numWords;

    for (int i = 0; i < numWords; i++)
    {
      std::string word;
      file >> word;
      words.push_back(word);
    }
    file.close();
  }
  else
  {
    std::cout << "Error in open file with words... Closing game.....";
    continueRunning = false;
  }

  return continueRunning;
}

bool WriteFile(std::string& filePath, std::vector<std::string>& words)
{
  std::ofstream file;
  file.open(filePath);
  bool continueRunning = true;

  if (file.is_open())
  {
    file << words.size() << std::endl;

    for (int i = 0; i < words.size(); i++)
    {
      file << words[i] << std::endl;
    }
    file.close();
  }
  else
  {
    std::cout << "Error in open file with words... Closing game.....";
    continueRunning = false;
  }

  return continueRunning;
}