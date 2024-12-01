#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

int main()
{
	// Parse input file
	std::ifstream file("src/day1/input.txt");

	std::vector<int> left_list{}, right_list{};

	std::string line{};
	while (std::getline(file, line))
	{
		int left{}, right{};
		std::sscanf(line.c_str(), "%d   %d", &left, &right);

		left_list.push_back(left);
		right_list.push_back(right);
	}

	file.close();

	////////////
	// PART 1 //
	////////////

	std::sort(left_list.begin(), left_list.end());
	std::sort(right_list.begin(), right_list.end());

	int total_distance = 0;
	for (int i = 0; i < left_list.size(); i++)
	{
		total_distance += abs(left_list[i] - right_list[i]);
	}

	std::cout << "Total distance : " << total_distance << "\n";

	////////////
	// PART 2 //
	////////////

	std::unordered_map<int, int> right_counts{};
	for (int& v : right_list)
	{
		right_counts[v] += 1;
	}

	int similarity_score = 0;
	for (int& v : left_list)
	{
		similarity_score += v * right_counts[v];
	}

	std::cout << "Similarity score : " << similarity_score << "\n";

	return 0;
}