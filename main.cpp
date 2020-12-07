#include <chrono>
#include <iostream>
#include <sstream>

#include "Input.h"

#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"

void DayOne(const std::string);
void DayTwo(const std::string);
void DayThree(const std::string);
void DayFour(const std::string);
void DayFive(const std::string);
void DaySix(const std::string);
void DaySeven(const std::string);

int main()
{
	/*
	{
		std::cout << "\tDay 1\n";
		DayOne("PuzzleInput/Day1Input.txt");
	}
	{
		std::cout << "\n\tDay 2\n";
		DayTwo("PuzzleInput/Day2Input.txt");
	}
	{
		std::cout << "\n\tDay 3\n";
		DayThree("PuzzleInput/Day3Input.txt");
	}
	{
		std::cout << "\n\tDay 4\n";
		DayFour("PuzzleInput/Day4Input.txt");
	}
	{
		std::cout << "\n\tDay 5\n";
		DayFive("PuzzleInput/Day5Input.txt");
	}
	{
		std::cout << "\n\tDay 6\n";
		DaySix("PuzzleInput/Day6Input.txt");
	}*/
		{
		std::cout << "\n\tDay 7\n";
		DaySeven("PuzzleInput/Day7Input.txt");
	}
}

void DayOne(const std::string path) {
	std::vector<int> data = Input::GetData<int>(path, '\n');
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day1::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day1::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayTwo(const std::string path) {
	std::vector<std::string> data = Input::GetData<std::string>(path, '\n');
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day2::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day2::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayThree(const std::string path) {
	std::vector<std::string> data = Input::GetData<std::string>(path);
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day3::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day3::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayFour(const std::string path) {
	std::vector<std::string> data = Input::GetEmptyNewLineData(path);
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

void DayFive(const std::string path) {
	std::vector<std::string> data = Input::GetData<std::string>(path);
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day5::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day5::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DaySix(const std::string& path) {
	std::vector<std::string> data = Input::GetEmptyNewLineData(path);
	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long int res = Day6::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day6::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DaySeven(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day7::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day7::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}