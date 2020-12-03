#ifndef DAY2
#define DAY2

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace Day2
{
	int PartA(const std::vector<std::string>& data) {
		int valid = 0;

		for(const auto&s : data) {
			int min, max, occurence;
			char req;

			std::stringstream ss(s);
			auto str = std::string{};
			while (ss >> str) {
				int pos;
				if (str.find('-') != std::string::npos) {
					pos = str.find('-');
					min = std::stoi(str.substr(0, s.find('-')));
					max = std::stoi(str.substr(pos + 1, str.size() - 1));
				} else if (str.find(':') != std::string::npos) {
					req = str[0];
				} else { 
					occurence = std::count(str.begin(), str.end(), req);
					if(occurence >= min && occurence <= max) {
						valid++;
					}
				}
			}
		}
		return valid;
	}

	int PartB(const std::vector<std::string>& data) {
		int valid = 0;

		for(const auto&s : data) {
			int first, second, occurence;
			char req;
			std::stringstream ss(s);
			auto str = std::string{};
			while (ss >> str) {
				int pos;
				if (str.find('-') != std::string::npos) {
					pos = str.find('-');
					first = std::stoi(str.substr(0, s.find('-'))) - 1;
					second = std::stoi(str.substr(pos+1, str.size() - 1)) - 1;
				} else if (str.find(':') != std::string::npos) {
					req = str[0];
				} else {
					if(str[first] == req ^ str[second] == req) valid++;
				}
			}
		}
		
		return valid;
	}
}
#endif