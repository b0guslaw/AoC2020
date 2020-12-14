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
		int arrival = std::stoi(data[0]);
		std::string table = data[1];
		table.erase(std::remove(table.begin(), table.end(), 'x'), table.end());
		std::map<int, int> timetable;
		std::string delim = ",";
		auto start = 0U; auto end = table.find(delim);
		while( end != std::string::npos ) {
			std::string t = table.substr(start, end - start);
			if (!t.empty()) timetable[std::stoi(t)];
			else timetable[0]++;
			start = end + delim.length();
			end = table.find(delim, start);
		}
		timetable[std::stoi(table.substr(start, end))];

		int min = -1;
		uint64_t mult = 0;
		for (const auto& [id, time] : timetable) {
			min++;
			if (id == 0) continue;
			if (min == 0) mult = (std::uint64_t)id;
			else timetable[id] = id - (min % id);
		}

		std::uint64_t timestamp = 0;
		for (auto [id, time] : timetable) {
			std::cout << id << ": " << time << "\n";
			while ((timestamp % id) != time) timestamp += mult;
			mult *= id;
			std::cout << timestamp << "\n";
		}
		return timestamp;
	}
}

#endif