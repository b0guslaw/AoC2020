#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

/**
 * This struct provides a simple and easy wrapper to import the contents of a file into
 * a std::vector. The ctor accepts one parameter and one optional parameter
 * Params: string to the path, (optional) char which delimiter to use
 * 
 * After calling the ctor, the public member data is accessible
 */
template <typename T>
struct Input {
	std::vector<T> data;
	Input(const std::string& path, char delim = ' ') {
		try {
			std::ifstream infile(path);
			std::string line;
			while(std::getline(infile, line, delim)) {
				T element;
				std::stringstream input(line);
				while(input >> element)
					data.push_back(element);
			}
		} catch (...) {
			std::cout << "An error occured!\n";
		}
	}
};

#endif