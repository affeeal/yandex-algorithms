#include <iostream>
#include <map>
#include <string>

// решение на C++ по каким-то причинам не принимается, но
// идентичное на Go проходит без проблем.

int main()
{
	std::string s;
	std::cin >> s;
	std::map<char, int> counts;
	int n = s.length();
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int count = (n - left) * (left + 1);
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
