#ifndef DAY4
#define DAY4

#include <regex>
#include <vector>
#include <algorithm>

namespace Day4
{
	bool countFields(const std::string& passport) {
		std::istringstream iss(passport);
		std::string field;
		int tracker = 0;
		while (iss >> field) {
			const auto& key = field.substr(0, field.find(":"));
			if (key == "byr" || key == "iyr" || key == "eyr" || key == "hgt" ||
				key == "hcl" || key == "ecl" || key == "pid") tracker++;
		}
		return tracker == 7;
	}

	bool isValid(const std::string& passport) {
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
				if (value.length() != 7 || value[0] != '#') return false;
				if (std::all_of(value.begin() + 1, value.end(), [](const char& c){
					return (48 <= c && c <= 57) || (97 <= c && c <= 102);
				})) {
						tracker++;
					}
				else return false;
			}
			if (key == "ecl") {
				if (value == "amb" || value == "blu" 
					|| value == "brn" || value == "gry" || 
					value == "grn" || value == "hzl" || value == "oth") tracker++;
				else return false;
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
		for (const auto& passport : data) {
			valid += countFields(passport);
		}
		return valid;
	}

	int PartB(const std::vector<std::string>& data) {
		int valid = 0;
		for (const auto& passport : data) valid += isValid(passport);
		return valid;
	}

}

#endif