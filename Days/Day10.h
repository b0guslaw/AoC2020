#ifndef DAY10
#define DAY10

#include <vector>
#include <algorithm>
#include <iostream>
#include <array>

namespace Day10
{
	int PartA(std::vector<int>& data) {
		std::array<int, 2> dist{0, 1};
		std::sort(data.begin(), data.end());
		data.insert(data.begin(), 0);
		
		for (int i = 1; i < data.size(); i++) {
			if (data[i] - data[i - 1] == 1) dist[0]++;
			if (data[i] - data[i - 1] == 3) dist[1]++;
		}
		return dist[0] * dist[1];
	}

	int64_t PartB(std::vector<int>& data) {
		std::vector<std::int64_t> paths(data.size());
		paths[data.size() - 1] = 1;
		for (int i = data.size() - 2; i >= 0; i--)
			for (int j = i + 1; j < data.size() && data[j] - data[i] < 4; j++)
				paths[i] += paths[j];
		return paths[0];
	}
}

#endif