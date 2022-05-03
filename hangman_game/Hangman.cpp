#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string filePath = "words.txt";
vector<string> words;

string secretWord;
vector<char> lettersBids;
bool isRunning = true;
int maxBidsWrong = 10;

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

void PrintSecretWord()
{
  for (char letter : secretWord)
  {
    if (ThisBidIsGone(letter))
    {
      cout << letter << "";
    }
    else
    {
      cout << "_";
    }
  }
  cout << endl;
}

void ReadFile()
{
  ifstream file;
  file.open(filePath);

  if (file.is_open())
  {
    int numWords;
    file >> numWords;

    for (int i = 0; i < numWords; i++)
    {
      string word;
      file >> word;
      words.push_back(word);
    }
    file.close();
  }
  else
  {
    cout << "Error in open file with words... Closing game.....";
    isRunning = false;
  }
}

void WriteFile()
{
  ofstream file;
  file.open(filePath);

  if (file.is_open())
  {
    file << words.size() << endl;

    for (int i = 0; i < words.size(); i++)
    {
      file << words[i] << endl;
    }
    file.close();
  }
  else
  {
    cout << "Error in open file with words... Closing game.....";
    isRunning = false;
  }
}

void CheckingRules()
{
  int bidsWrong = 0;
  int hits = 0;
  int hitsNeeded = secretWord.size();

  for (char letter : secretWord)
  {
    if (ThisBidIsGone(letter))
    {
      hits++;
    }
  }

  for (char letter : lettersBids)
  {
    if (!ThisBidIsRight(letter))
    {
      bidsWrong++;
    }
  }

  if (hits == hitsNeeded)
  {
    cout << "You win the game!!" << endl;
    cout << "Do you want to add a word to the database? Y - Yes / N - No" << endl;
    char answer;
    cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
      cout << "Type a word:" << endl;
      string word;
      cin >> word;
      words.push_back(word);
      WriteFile();
    }
    isRunning = false;
  }

  if (bidsWrong == maxBidsWrong)
  {
    cout << "You lose the game. The Secret Word is " << secretWord << endl;
    isRunning = false;
  }
}

void Game()
{
  cout << "You need to guess the word" << endl;
  while (isRunning)
  {
    PrintSecretWord();
    char letterBid;
    cin >> letterBid;
    bool isGone = ThisBidIsGone(letterBid);
    if (isGone)
    {
      cout << "That letter is gone, try other letter" << endl;
    }
    else
    {
      lettersBids.push_back(letterBid);
      bool isRight = ThisBidIsRight(letterBid);
      if (isRight)
      {
        cout << "You hit the bid!!" << endl;
      }
      else
      {
        cout << "You miss the bid :(" << endl;
      }
    }
    CheckingRules();
  }
}

void Introduction()
{
  cout << "*********************************" << endl;
  cout << "**** Welcome to Hangman Game ****" << endl;
  cout << "*********************************" << endl;
  ReadFile();

  srand(time(NULL));
  int randomIndex = rand() % words.size();
  secretWord = words[randomIndex];
}

int main()
{
  Introduction();
  Game();
}
