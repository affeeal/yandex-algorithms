#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main()
{
	auto k = 0;
	std::string s;
	std::cin >> k >> s;
	std::map<char, int> m;
	for (auto ch = 'a'; ch <= 'z'; ch++)
	{
		auto replacements = k;
		auto left = 0;
		auto right = 0;
		while (left < s.length())
		{
			while (right < s.length())
			{
				if (s[right] != ch)
				{
					if (replacements > 0) replacements--;
					else break;
				}
				right++;
			}
			m[ch] = std::max(right - left, m[ch]);
			if (s[left] != ch) replacements++;
			left++;
		}
	}
	std::cout
		<< std::max_element(
			m.begin(),
			m.end(),
			[](const auto& x, const auto& y) { return x.second < y.second; }
			)->second
		<< std::endl;
	return 0;
}
