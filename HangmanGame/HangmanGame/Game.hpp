#pragma once
#include <iostream>

namespace Hangman {
	void Introduction();
	void Game();
	inline void TextIntroduction()
	{
		std::cout << "*********************************" << std::endl;
		std::cout << "**** Welcome to Hangman Game ****" << std::endl;
		std::cout << "*********************************" << std::endl;
	}
}
