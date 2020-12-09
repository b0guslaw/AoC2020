#ifndef DAY8
#define DAY8

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

namespace Day8
{

	bool Run(const std::vector<std::string> data, int& acc) {
		std::vector<int> cache;
		int offset = 1;
		for (int i = 0; i < data.size(); i = i + offset) {
			offset = 1;
			std::stringstream stream(data[i]);
			std::string ins ,val;
			stream >> ins >> val;
			if (std::find(cache.begin(), cache.end(), i) == cache.end()) {
				cache.push_back(i);
			} else {
				return false;
			}
			if (ins == "nop") continue;
			if (ins == "acc") acc += std::stoi(val);
			if (ins == "jmp") offset = std::stoi(val);
		}
		return true;;
	}
	int PartA(const std::vector<std::string>& data) {
		int acc = 0;
		Run(data, acc);
		return acc;
	}

	int PartB(const std::vector<std::string>& data) {
		int acc = 0, k = 0;

		std::vector<int> patches;
		while(true) {
			// make new data
			auto newData = data;

			// replace nop with jmp or jmp with nop, but only if the index is new
			for (; k < newData.size(); k++) {
				if(newData[k].starts_with("nop") && (std::find(patches.begin(), patches.end(), k) == patches.end()) ) {
					newData[k].replace(0, 3, "jmp");
					patches.push_back(k);
					break;
				}
				if(newData[k].starts_with("jmp") && ( std::find( patches.begin(), patches.end(), k) == patches.end() ) ) {
					newData[k].replace(0, 3, "nop");
					patches.push_back(k);
					break;
				}
			}
			if (Run(newData, acc)) break;
			acc = 0;
		}
		return acc;
	}
}

#endif