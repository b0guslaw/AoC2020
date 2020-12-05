#include <chrono>
#include <iostream>

#include "Input.h"

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"

void DayOne(const Input<int>&);
void DayTwo(const Input<std::string>&);
void DayThree(const Input<std::string>&);
void DayFour();
void DayFive(const Input<std::string>&);

int main()
{
	{
		std::cout << "\tDay 1\n";
		Input<int> in("PuzzleInput/Day1Input.txt", '\n');
		DayOne(in);
	}
	{
		std::cout << "\n\tDay 2\n";
		Input<std::string> in("PuzzleInput/Day2Input.txt");
		DayTwo(in);
	}
	{
		std::cout << "\n\tDay 3\n";
		Input<std::string> in("PuzzleInput/Day3Input.txt");
		DayThree(in);
	}
	{
		std::cout << "\tDay 4\n";
		DayFour();
	}
	{
		std::cout << "\tDay 5\n";
		Input<std::string> in("PuzzleInput/Day5Input.txt", '\0');
		DayFive(in);

	}
}

void DayOne(const Input<int>& in) {
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day1::PartA(in.data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day1::PartB(in.data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayTwo(const Input<std::string>& in) {
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day2::PartA(in.data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day2::PartB(in.data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayThree(const Input<std::string>& in) {
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day3::PartA(in.data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day3::PartB(in.data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayFour() {
	std::ifstream infile("PuzzleInput/Day4Input.txt");

	std::vector<std::string> data;
	std::string passport;

	for (std::string line; std::getline(infile, line); ) {
		if (line.empty()) {
			data.push_back(passport);
			passport.clear();
		}
		if (infile.eof()) {
			passport += line;
			data.push_back(passport);
		}
		passport += line;
		passport += " ";
	}

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day4::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day4::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayFive(const Input<std::string>& in) {
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day5::PartA(in.data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day5::PartB(in.data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}