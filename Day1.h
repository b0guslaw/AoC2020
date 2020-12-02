#ifndef DAY1
#define DAY1

#include <unordered_set>
#include <vector>

namespace Day1
{
	int PartA(const std::vector<int>& data) {
		for (size_t i = 0; i < data.size(); i++) {
			for (size_t j = 1; j < data.size(); j++) {
				if (i == j) continue;
				if (data[i] + data[j] == 2020)
					return data[i] * data[j];
			}
		}
		return 0;
	}

	int PartB(const std::vector<int>& data) {
		for (size_t i = 0; i < data.size(); i++) {
			std::unordered_set<int> set(data.begin(), data.end());
			int res = 2020 - data[i];
			for (size_t j = 1; j < data.size(); j++) {
				if (set.find(res - data[j]) != set.end())
					return data[i] * data [j] * (res - data[j]);
				set.insert(data[j]);
			}
		}
		return 0;
	}
}

#endif