#ifndef DAY6
#define DAY6

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

namespace Day6
{
	int PartA(const std::vector<std::string>& data) {
		int sum = 0;
		std::set<char> answers;
		for (const auto& group : data) {
			for(auto& answer : group) {
				if (answer != ' ')
					answers.insert(answer);
			}
			sum += answers.size();
			answers.clear();
		}
		return sum;
	}

	int PartB(const std::vector<std::string>& data) {
		int sum = 0;
		for (const auto& group : data) {
			std::istringstream iss(group);
			int required = std::distance(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>());
			std::unordered_map<char, int> answers;
			for(auto& answer : group) {
				if (answer != ' ')
					answers[answer]++;
			}
			for(auto answer : answers) {
				if (answer.second >= required) {
					sum++;
				}
			}
		}
		return sum;
	}
}

#endif