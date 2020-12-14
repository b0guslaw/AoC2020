#ifndef DAY12
#define DAY12

#include <string>
#include <vector>

namespace Day12
{
	void TurnR(int& currDegree, int deltaDegree) { 
		currDegree = (currDegree + deltaDegree / 90) % 4;
	}

	void TurnL(int& currDegree, int deltaDegree) { 
		currDegree = (currDegree + 4 - deltaDegree / 90) % 4;
	}

	int PartA(const std::vector<std::string>& data) {
		std::pair<int, int> coordinates = {0, 0};
		int direction = 1; // 0: N, 1: E, 2: S, 3: W 
		for (const auto& instruction : data) {
			int value = std::stoi(instruction.substr(1));
			switch (instruction[0]) {
				case 'N':
					coordinates.first += value;
					break;
				case 'S':
					coordinates.first -= value;
					break;
				case 'E':
					coordinates.second += value;
					break;
				case 'W':
					coordinates.second -= value;
					break;
				case 'F':
					if (direction == 0) coordinates.first += value;
					if (direction == 1) coordinates.second += value;
					if (direction == 2) coordinates.first -= value;
					if (direction == 3) coordinates.second -= value;
					break;
				case 'R':
					TurnR(direction, value);
					break;
				case 'L':
					TurnL(direction, value);
					break;
				
			}
		}
		return std::abs(coordinates.first) + std::abs(coordinates.second);
	}

	int PartB(const std::vector<std::string>& data) {
		std::array<int, 4> waypoint{10, 0, 0, 1};
		std::array<int, 4> ship{0, 0, 0, 0};
		for (const auto& instruction : data) {
			int value = std::stoi(instruction.substr(1));
			switch (instruction[0]) {
				case 'N':
					waypoint[3] += value;
					break;
				case 'S':
					waypoint[1] += value;
					break;
				case 'E':
					waypoint[0] += value;
					break;
				case 'W':
					waypoint[2] += value;
					break;
				case 'F':
					for (int i = 0; i < 4; i++) ship[i] += value * waypoint[i];
					break;
				case 'R':
					std::rotate(waypoint.rbegin(), waypoint.rbegin() + value / 90, waypoint.rend());
					break;
				case 'L':
					std::rotate(waypoint.begin(), waypoint.begin() + value / 90, waypoint.end());
					break;
			}
		}
		return std::abs(ship[3] - ship[1]) + std::abs(ship[0] - ship[2]);
	}
}

#endif