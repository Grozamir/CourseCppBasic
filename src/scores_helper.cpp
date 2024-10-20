#include "scores_helper.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

bool add_or_change_score(const std::string& username, const int score)
{
	std::ifstream in_file{ high_scores_filename };
	std::ofstream out_file{ temp_filename, std::ios_base::app };
	if (!out_file.is_open() && !in_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return false;
	}

	bool is_found_user = false;
	std::string temp_username;
	int temp_score;
	while (true)
	{
		in_file >> temp_username;
		in_file >> temp_score;

		if (in_file.fail()) {
			break;
		}
		if (temp_username == username)
		{
			is_found_user = true;
			temp_score = std::min(temp_score, score);
		}
		out_file << temp_username << ' ' << temp_score << '\n';
	}
	if (!is_found_user)
	{
		out_file << username << ' ' << score << '\n';
	}

	in_file.close();
	out_file.close();

	if (std::remove(high_scores_filename.c_str()))
	{
		std::cout << "Failed remove file!" << '\n';
		return false;
	}
	if (std::rename(temp_filename.c_str(), high_scores_filename.c_str()))
	{
		std::cout << "Failed rename file!" << '\n';
		return false;
	}

	return true;
}

void print_all_results()
{
	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return;
	}

	std::cout << "High scores table:" << std::endl;

	std::string username;
	int high_score = 0;
	while (true) {
		in_file >> username;
		in_file >> high_score;
		in_file.ignore();

		if (in_file.fail()) {
			break;
		}

		std::cout << username << '\t' << high_score << std::endl;
	}
}

void print_best_results()
{
	std::ifstream in_file{ high_scores_filename };
	if (!in_file.is_open()) {
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return;
	}
	
	std::unordered_map<std::string, int> best_results;

	{
		std::string username;
		int high_score = 0;
		while (true) {
			in_file >> username;
			in_file >> high_score;
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}
			if (!best_results.contains(username) || best_results[username] < high_score)
			{
				best_results[username] = high_score;
			}
		}
	}

	std::cout << "High scores table:" << std::endl;
	for (const auto& [username, best_score] : best_results)
	{
		std::cout << username << '\t' << best_score << std::endl;
	}
}