#include <chrono>
#include <iostream>

#include "Input.h"

#include "Day1.h"
#include "Day2.h"

void DayOne(const Input&);
void DayTwo(const Input&);

int main()
{
	{
		std::cout << "\tDay 1\n";
		Input in("PuzzleInput/Day1Input.txt", '\n', Mode::INTEGER);
		DayOne(in);
	}
	{
		std::cout << "\n\tDay 2\n";
		Input in("PuzzleInput/Day2Input.txt");
		DayTwo(in);
	}
}

void DayOne(const Input& in) {
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day1::PartA(in.idata);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day1::PartB(in.idata);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}

void DayTwo(const Input& in) {
	auto start = std::chrono::high_resolution_clock::now();
	int res = Day2::PartA(in.sdata);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part A: " << res <<" found after " << duration << "µs\n";

	start = std::chrono::high_resolution_clock::now();
	res = Day2::PartB(in.sdata);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Part B: " << res <<" found after " << duration << "µs\n";
}