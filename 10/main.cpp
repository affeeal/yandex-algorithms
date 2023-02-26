#include <cstdint>
#include <iostream>
#include <map>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;
	std::map<char, uint64_t> counts;
	uint64_t n = s.length();
	uint64_t left = 0;
	uint64_t right = n - 1;
	while (left <= right)
	{
		uint64_t count = (n - left) * (left + 1);
		counts[s[left]] += count;
		if (left != right)
			counts[s[right]] += count;
		left++;
		right--;
	}
	for (const auto& p : counts)
		std::cout << p.first << ':' << ' ' << p.second << std::endl;
	return 0;
}
