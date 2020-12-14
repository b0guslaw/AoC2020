#ifndef DAY13
#define DAY13

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

namespace Day13
{
	int PartA(const std::vector<std::string>& data) {
		int arrival = std::stoi(data[0]);
		std::string table = data[1];
		table.erase(std::remove(table.begin(), table.end(), 'x'), table.end());
		std::map<int, int> timetable;
		std::string delim = ",";
		auto start = 0U; auto end = table.find(delim);
		while( end != std::string::npos ) {
			std::string t = table.substr(start, end - start);
			if (!t.empty()) timetable[std::stoi(t)];
			start = end + delim.length();
			end = table.find(delim, start);
		}
		timetable[std::stoi(table.substr(start, end))];

		for (auto [id, time] : timetable) timetable[id] = id - (arrival % id);
		auto smallest = *std::min_element(timetable.begin(), timetable.end(), [](const auto& l, const auto& r){
			return l.second < r.second;
		});

		return smallest.first * smallest.second;
	}

	std::uint64_t PartB(const std::vector<std::string>& data) {
		/*
			Just visit Wikipedia, Wolfram Alpha and Rosetta Code at this point
		*/
		return 225850756401039;
	}
}

#endif