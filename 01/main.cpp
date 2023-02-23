#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void error(std::string message)
{
	std::cerr << "error: " << message << std::endl;
	exit(EXIT_FAILURE);
}

int main()
{
	std::ifstream input;
	input.open("input.txt");
	if (!input.is_open()) error("open input.txt");

	std::string str;
	std::map<char, int> m;
	while (getline(input, str))
		for(const auto& ch : str)
			if (ch != ' ' && ch != '\n') m[ch]++;
	
	input.close();
	auto max = 0;
	for (const auto& p : m)
		max = p.second > max ? p.second : max;

	for (auto i = 0; i < max; ++i)
	{
		for (const auto& p : m)
			if (p.second >= max - i) std::cout << '#';
			else std::cout << ' ';
		std::cout << std::endl;
	}

	for (const auto& p : m)
		std::cout << p.first;
	std::cout << std::endl;
	
	exit(EXIT_SUCCESS);
}
