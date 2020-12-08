#ifndef DAY8
#define DAY8

#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
#include <algorithm>

namespace Day8
{

	std::unordered_map<int, std::string> Run(const std::vector<std::string> data, int& acc) {
		std::unordered_map<int, std::string> cache;
		
		int offset = 1;
		for (int i = 0; i < data.size(); i = (i + offset) % data.size()) {
			offset = 1;
			std::stringstream stream(data[i]);
			std::string ins ,val;
			stream >> ins >> val;
			if (cache.find(i) == cache.end()) {
				cache.emplace(i, ins);
			} else {
				return cache;
			}

			if (ins == "nop") continue;
			if (ins == "acc") acc += std::stoi(val);
			if (ins == "jmp") offset = std::stoi(val);

		}
		return cache;
	}
	int PartA(const std::vector<std::string>& data) {
		int acc = 0;
		Run(data, acc);
        return acc;
	}

	int PartB(const std::vector<std::string>& data) {
		int acc = 0;
        
		

		return 0;
	}
}

#endif