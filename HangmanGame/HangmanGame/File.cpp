#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "File.hpp"

extern std::string filePath;
extern bool isRunning;
extern std::vector<std::string> words;

void ReadFile()
{
  std::ifstream file;
  file.open(filePath);

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
    isRunning = false;
  }
}

void WriteFile()
{
  std::ofstream file;
  file.open(filePath);

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
    isRunning = false;
  }
}