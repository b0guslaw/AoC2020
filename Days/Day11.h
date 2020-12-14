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

	constexpr std::array<std::pair<int, int>, 8> Directions = {{
		 {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
	}};

	int CountOccupiedB(const std::vector<std::string>& grid, int i, int j) {
		int occupied = 0;
		auto IsOccupied = [&](const char& seat, const int& di, const int& dj) {
			return di >= 0 && di < grid.size() && dj >= 0 && dj < grid[0].size() && seat == '#';
		};
		auto IsEmpty = [](const char& seat) { return seat == '.'; };

		for (const auto& [iOff, jOff] : Directions) {
			int offset = 1;
			int di, dj;
			while (true) {
				di = i + iOff * offset;
				dj = j + jOff * offset;
				offset++;
				if (!(di >= 0 && di < grid.size() && dj >= 0 && dj < grid[0].size() && IsEmpty(grid[di][dj]))) break;
			};
			occupied += IsOccupied(grid[di][dj], di, dj);
		}
		return occupied;
	}

	int CountOccupiedA(const std::vector<std::string>& grid, int i, int j) {
		auto IsOccupied = [](const char& seat) { return seat == '#'; };
		return IsOccupied(grid[i - 1][j - 1]) + IsOccupied(grid[i - 1][j]) + IsOccupied(grid[i - 1][j + 1]) +
					IsOccupied(grid[i][j - 1]) + IsOccupied(grid[i][j + 1]) +
					IsOccupied(grid[i + 1][j - 1]) + IsOccupied(grid[i + 1][j]) + IsOccupied(grid[i + 1][j + 1]);
	}

	void RunSimulationA(std::vector<std::string>& seats) {
		auto temp = seats;
		while (true) {
			for (int i = 1; i < temp.size() - 1; i++) {
				for (int j = 1; j < temp[i].size() - 1; j++) {
					if (seats[i][j] == '.') continue;
					else if (seats[i][j] == 'L' &&
						CountOccupiedA(seats, i, j) == 0) temp[i][j] = '#';
					else if (seats[i][j] == '#' &&
						CountOccupiedA(seats, i, j) >= 4) temp[i][j] = 'L'; 
					}
				}
			if (temp == seats) return;
			seats = temp;
		}

	}

	void RunSimulationB(std::vector<std::string>& seats) {
		auto temp = seats;
		while (true) {
			for (int i = 0; i < seats.size(); i++) {
				for (int j = 0; j < seats[0].size(); j++) {
					int occupied = CountOccupiedB(seats, i , j);
					if (seats[i][j] == '.') continue;
					if (seats[i][j] == 'L' && occupied == 0) temp[i][j] = '#';
					else if (seats[i][j] == '#' && occupied >= 5) temp[i][j] = 'L';
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
		RunSimulationA(data);
		int count = 0;
		for (auto line : data)
			for (auto seat : line)
				if (seat == '#') count++;
		return count;
	}

	int PartB(std::vector<std::string> data) {
		int count = 0;
		RunSimulationB(data);
		for (auto line : data)
			for (auto seat : line)
				if (seat == '#') count++;
		return count;
	}
}

#endif