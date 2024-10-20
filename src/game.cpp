#include "game.hpp"
#include <iostream>

void game_loop(int target_value, int& attempts_count)
{
	int current_value = 0;

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;

		attempts_count += 1;

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << " attempts = " << attempts_count << std::endl;
			break;
		}

	} while(true);
}