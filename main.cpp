#include <chrono>
#include <iostream>
#include <sstream>

#include "Input.h"

#include "Days/Day1.h"
#include "Days/Day2.h"
#include "Days/Day3.h"
#include "Days/Day4.h"
#include "Days/Day5.h"
#include "Days/Day6.h"
#include "Days/Day7.h"
#include "Days/Day8.h"
#include "Days/Day9.h"
#include "Days/Day10.h"
#include "Days/Day11.h"
#include "Days/Day12.h"
#include "Days/Day13.h"
#include "Days/Day14.h"

void Day1f(const std::string);
void Day2f(const std::string);
void Day3f(const std::string);
void Day4f(const std::string);
void Day5f(const std::string);
void Day6f(const std::string);
void Day7f(const std::string);
void Day8f(const std::string);
void Day9f(const std::string);
void Day10f(const std::string);
void Day11f(const std::string);
void Day12f(const std::string);
void Day13f(const std::string);
void Day14f(const std::string);

int main()
{
	/*std::cout << "\n\tDay 1\n"; Day1f("PuzzleInput/Day1Input.txt");
	std::cout << "\n\tDay 2\n"; Day2f("PuzzleInput/Day2Input.txt");	
	std::cout << "\n\tDay 3\n"; Day3f("PuzzleInput/Day3Input.txt");
	std::cout << "\n\tDay 4\n"; Day4f("PuzzleInput/Day4Input.txt");
	std::cout << "\n\tDay 5\n"; Day5f("PuzzleInput/Day5Input.txt");
	std::cout << "\n\tDay 6\n"; Day6f("PuzzleInput/Day6Input.txt");
	std::cout << "\n\tDay 7\n"; Day7f("PuzzleInput/Day7Input.txt");
	std::cout << "\n\tDay 8\n"; Day8f("PuzzleInput/Day8Input.txt");
	std::cout << "\n\tDay 9\n"; Day9f("PuzzleInput/Day9Input.txt");
	std::cout << "\n\tDay 10\n"; Day10f("PuzzleInput/Day10Input.txt");
	std::cout << "\n\tDay 11\n"; Day11f("PuzzleInput/Day11Input.txt");
	std::cout << "\n\tDay 12\n"; Day12f("PuzzleInput/Day12Input.txt");
	std::cout << "\n\tDay 13\n"; Day13f("PuzzleInput/Day13Input.txt");*/
	std::cout << "\n\tDay 14\n"; Day14f("PuzzleInput/Day14Input.txt");
}

void Day1f(const std::string path) {
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

void Day2f(const std::string path) {
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

void Day3f(const std::string path) {
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

void Day4f(const std::string path) {
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

void Day5f(const std::string path) {
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

void Day6f(const std::string path) {
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

void Day7f(const std::string path) {
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

void Day8f(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day8::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day8::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day9f(const std::string path) {
	std::vector<int> data = Input::GetData<int>(path);
	auto start = std::chrono::high_resolution_clock::now();

	int res = Day9::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day9::PartB(data, res);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day10f(const std::string path) {
	std::vector<int> data = Input::GetData<int>(path);

	auto start = std::chrono::high_resolution_clock::now();
	std::int64_t res = Day10::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day10::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day11f(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day11::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day11::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day12f(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day12::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day12::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day13f(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	std::uint64_t res = Day13::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day13::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void Day14f(const std::string path) {
	std::vector<std::string> data = Input::GetStringData(path);
	auto start = std::chrono::high_resolution_clock::now();
	std::uint64_t res = Day14::PartA(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day14::PartB(data);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}