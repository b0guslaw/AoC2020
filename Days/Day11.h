#ifndef DAY11
#define DAY11

#include <vector>
#include <string>
#include <iostream>

namespace Day11
{
	void PrintStatus(const std::vector<std::string>& seats) {
		for (int i = 0; i < seats.size() + 4; i++) std::cout << "+";
		for (const auto& s : seats) std::cout << "\n+ " << s << " +";
		std::cout << "\n";
		for (int i = 0; i < seats.size() + 4; i++) std::cout << "+";
		std::cout << "\n";
	}

	int CountOccupied(const std::vector<std::string>& grid, int i, int j) {
		auto IsOccupied = [](const char& seat) { return seat == '#'; };
		return IsOccupied(grid[i - 1][j - 1]) + IsOccupied(grid[i - 1][j]) + IsOccupied(grid[i - 1][j + 1]) +
					IsOccupied(grid[i][j - 1]) + IsOccupied(grid[i][j + 1]) +
					IsOccupied(grid[i + 1][j - 1]) + IsOccupied(grid[i + 1][j]) + IsOccupied(grid[i + 1][j + 1]);
	}

	void RunSimulation(std::vector<std::string>& seats) {
		auto temp = seats;
		while (true) {
			for (int i = 1; i < temp.size() - 1; i++) {
				for (int j = 1; j < temp[i].size() - 1; j++) {
					if (seats[i][j] == '.') continue;
					else if (seats[i][j] == 'L' &&
						CountOccupied(seats, i, j) == 0) temp[i][j] = '#';
					else if (seats[i][j] == '#' &&
						CountOccupied(seats, i, j) >= 4) temp[i][j] = 'L';
					}
				}
			if (temp == seats) return;
			seats = temp;
		}

	}

	int PartA(std::vector<std::string> data) {
		std::string pad(data[0].size(), '.');
		data.insert(data.begin(), pad);
		data.push_back(pad);
		for (auto& l : data) {
			l.insert(0, 1, '.');
			l += '.';
		}
		RunSimulation(data);
		int count = 0;
		for (auto line : data)
			for (auto seat : line)
				if (seat == '#') count++;
		return count;
	}

	int PartB(std::vector<std::string> data) {
		return 0;
	}
}

#endif