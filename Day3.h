#ifndef DAY3
#define DAY3

#include <unordered_set>
#include <vector>
#include <utility>

namespace Day3
{
	int PartA(const std::vector<std::string>& data) {
		int trees = 0;
		int x = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].at(x) == '#') {
				trees++;
			}
			x = (x + 3) % data[i].size();
		}
		return trees;
	}

	unsigned long long int PartB(const std::vector<std::string>& data) {
		std::vector<std::pair<int, int>> slopes = {
		  {1, 1},
		  {3, 1},
		  {5, 1},
		  {7, 1},
		  {1, 2},  
		};

		unsigned long long int trees = 1;

		for(const auto& slope : slopes) {
			unsigned int x = 0, treecount = 0;
			for (int i  = 0; i < data.size(); i += slope.second) {
				if (data[i].at(x) == '#') {
					treecount++;
				}
				x = (x + slope.first) % data[i].size();
			}
			trees *= treecount;
		}
		return trees;
	}
}

#endif