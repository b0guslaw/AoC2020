#ifndef DAY5
#define DAY5

#include <set>
#include <vector>
#include <algorithm>

namespace Day5
{
	int passID(const std::string& boardingpass) {
		int rlow = 0, rhigh = 127, clow = 0, chigh = 7;
		int row, col;
		for (int i = 0; i < 6; i++) {
				switch (boardingpass[i]) {
					case 'F':
						rhigh = (rhigh + rlow) / 2;
						break;
					case 'B':
						rlow = (rhigh + rlow) / 2 + 1;
						break;
				}
			}
			if (boardingpass[6] == 'B') row = rhigh;
			if (boardingpass[6] == 'F') row = rlow;
			for (int i = 7; i < 9; i++) {
				switch(boardingpass[i]) {
					case 'L':
						chigh = (chigh + clow) / 2;
						break;
					case 'R':
						clow = (chigh + clow) / 2 + 1;
						break;
				}
			}
			if (boardingpass[9] == 'R') col = chigh;
			if (boardingpass[9] == 'L') col = clow;
			return row * 8 + col;
	}

	int PartA(const std::vector<std::string>& data) {
		int max = 0;
		for (const auto& boardingpass : data) {
			int t = passID(boardingpass);
			if (t > max) max = t;
		}
		return max;
	}

	int PartB(const std::vector<std::string>& data) {
		std::set<int> passes;
		for (const auto& d : data) passes.emplace(passID(d));
		int missing = *passes.begin();
		for (auto it = passes.begin(); it != passes.end(); ++it, ++missing)
			if(*it != missing) return missing;	
		return 0;
	}
}

#endif