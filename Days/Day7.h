#ifndef DAY7
#define DAY7

#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using BagType 	= std::pair<int, std::string>;
using BagList 	= std::vector<BagType>;
using BagMap 	= std::unordered_map<std::string, BagList>;

namespace Day7
{
	int Contains(BagMap& bags, std::string inBag) {
	int count = 1;
	if (bags.find(inBag) != bags.end())
		for (auto b : bags.at(inBag)) count += b.first * Contains(bags, b.second);
	else return 1;
	return count;
}

	std::unordered_set<std::string> gold;
	bool CountBags(BagMap& bags, std::string bag) {
		if (bags.find(bag) != bags.end()) {
			for (auto b : bags.at(bag)) {
				if (b.second == "shiny gold") {
					gold.insert(bag);
					return true;
				}
				if (CountBags(bags, b.second)) {
					gold.insert(bag);
					return true; 
				}
			}
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

		for (auto bag : bags) CountBags(bags, bag.first);
		return gold.size();
	}

	int PartB(const std::vector<std::string>& data) {
		BagMap bags = ProcessInput(data);
		int count = 0;
		for(auto bag : bags.at("shiny gold"))
			count += bag.first * Contains(bags, bag.second);
		return count;
	}
}
#endif