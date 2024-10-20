#pragma once

#include <string>

const std::string high_scores_filename = "high_scores.txt";
const std::string temp_filename = "temp.txt";

bool add_or_change_score(const std::string& username, int score);
void print_all_results();
void print_best_results();