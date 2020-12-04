#ifndef DAY4
#define DAY4

#include <regex>
#include <vector>
#include <iostream>
#include <future>
#include <thread>

namespace Day4
{
	bool isValid(const std::string& passport, int i) {
		std::istringstream iss(passport);
		std::string field;
		int tracker = 0;
		while (iss >> field) {
			const auto& key = field.substr(0, field.find(":"));
			const auto& value = field.substr(field.find(":") + 1, field.length());
			if (key == "byr") {
				if(std::stoi(value) >= 1920 && std::stoi(value) <= 2002) tracker++;
				else return false;
			}
			if (key == "iyr") {
				if(std::stoi(value) >= 2010 && std::stoi(value) <= 2020) tracker++;
				else return false;
			}
			if (key == "eyr") {
				if(std::stoi(value) >= 2020 && std::stoi(value) <= 2030) tracker++;
				else return false;
			}
			if (key == "hgt") {
				if (value.ends_with("cm")) {
					if(std::stoi(value) >= 150 && std::stoi(value) <= 193) tracker++;
					else return false;
				}
				if (value.ends_with("in")) {
					if(std::stoi(value) >= 59 && std::stoi(value) <= 76) tracker++;
					else return false;
				}
			}
			if (key == "hcl") {
				std::regex regex("^#(?:[0-9a-f]{6})$");
				if (std::regex_search(value, regex)) tracker++;
				else return false;
			}
			if (key == "ecl") {
				std::regex regex("(amb)|(blu)|(brn)|(gry)|(grn)|(hzl)|(oth)");
				if (std::distance(
						std::sregex_iterator(value.begin(),
						value.end(), regex), std::sregex_iterator()) == 1) {
							tracker++;
						} else {
							return false;
						}
			}
			if (key == "pid") {
				if (value.length() == 9) tracker++;
				else return false;
			}
		}
		return tracker == 7;
	}

	int PartA(const std::vector<std::string>& data) {
		int valid = 0;
		std::regex regex("(byr)|(iyr)|(eyr)|(hgt)|(hcl)|(ecl)|(pid)");
		for (const auto& passport : data) {
			if (std::distance(
						std::sregex_iterator(passport.begin(),
						passport.end(), regex), std::sregex_iterator()) == 7) valid++;
		}
		return valid;
	}

	int PartB(const std::vector<std::string>& data) {
		int valid = 0;
		std::vector<std::future<bool>> future;
		for (size_t i = 0; i < data.size(); i++) {
			future.push_back(std::async(isValid, data[i], i));
		}

		for (auto& f : future) {
			valid += f.get();
		}
		return valid;
	}
}

#endif