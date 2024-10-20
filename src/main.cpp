#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "game.hpp"
#include "scores_helper.hpp"


int main(int argc, char** argv)
{
	int max_value = 100;

	if (argc >= 2) {
		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}

			int parameter_value = std::stoi(argv[2]);
			if (parameter_value > 0)
			{
				max_value = parameter_value;
			}
		}
		else if (arg1_value == "-table")
		{
			print_best_results();
			return 0;
		}
		else if (arg1_value == "-level")
		{
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-level' requires some value!" << std::endl;
				return -1;
			}

			int level_value = std::stoi(argv[2]);
			if (level_value == 1)
			{
				max_value = 10;
			}
			else if (level_value == 2)
			{
				max_value = 50;
			}
			else if(level_value == 3)
			{
				max_value = 100;
			}
		}
	}

	std::srand(std::time(nullptr));

	const int random_value = std::rand() % max_value;

	// std::cout << random_value << std::endl; // for testing

	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;
	
	int attempts_count = 0;
	game_loop(random_value, attempts_count);

	add_or_change_score(user_name, attempts_count);

	print_best_results();
}