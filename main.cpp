#include <chrono>
#include <iostream>

#include "Input.h"

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

void DayOne(const Input<int>&);
void DayTwo(const Input<std::string>&);
void DayThree(const Input<std::string>&);

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