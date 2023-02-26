#include <algorithm>
#include <cstdint>
#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int previous = -1, current = 0;
	int64_t count = 0;
	for (auto i = 0; i < N; i++)
	{
		std::cin >> current;
		if (previous != -1)
			count += std::min(previous, current);
		previous = current;
	}
	std::cout << count << std::endl;
	return 0;
}
