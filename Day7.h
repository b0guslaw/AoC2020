#ifndef DAY7
#define DAY7

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using BagType 	= std::pair<int, std::string>;
using BagList 	= std::vector<BagType>;
using BagMap 	= std::unordered_map<std::string, BagList>;

namespace Day7
{
	bool GoldHolder(BagList& list) {
		for (auto& l : list) {
			if (l.second == "shiny gold") return true;
		}
		return false;
	}

	BagMap ProcessInput(const std::vector<std::string>& data) {
		std::unordered_map<std::string, BagList> bags;
		for (const auto& entry : data) {
			std::string param1, param2, param3, skip;
			std::stringstream stream(entry);
			std::string bagParent;
			BagList children;
			while (stream >> param1 >> param2 >> param3 >> skip) {
				if (skip == "contain") {
					bagParent = param1 + " " + param2;
				}
				if (skip.ends_with(",")) {
					children.push_back(
						std::make_pair(std::stoi(param1), param2+ " " +param3)
					);
				}
				if (skip.ends_with(".")) {
					children.push_back(
						std::make_pair(std::stoi(param1), param2+ " " +param3)
					);
					bags.emplace(bagParent, children);
					break;
				}
			}
		}
		return bags;
	}

	int PartA(const std::vector<std::string>& data) {
		BagMap bags = ProcessInput(data);

		return countGoldbags(bags, "shiny gold");
	}

	int PartB(const std::vector<std::string>& data) {
		return 0;
	}
}

#endif