#include <iostream>
#include <set>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::set<int> diego_set;
	for (auto i = 0; i < N; i++)
	{
		int sticker;
		std::cin >> sticker;
		diego_set.insert(sticker);
	}
	
	int K;
	std::cin >> K;
	std::vector<int> collectors_vector;
	for (auto i = 0; i < K; i++)
	{
		int sticker;
		std::cin >> sticker;
		collectors_vector.push_back(sticker);
	}
	std::vector<int> diego_vector;
	
	for (const auto& sticker : diego_set)
		diego_vector.push_back(sticker);
	
	for (const auto& sticker : collectors_vector)
	{
		int low = 0;
		int high = diego_vector.size() - 1;
		while (low <= high)
		{
			int middle = (low + high) / 2;
			if (diego_vector[middle] < sticker)
				low = middle + 1;
			else high = middle - 1;
		}
		std::cout << low << std::endl;
	}
	return 0;
}
