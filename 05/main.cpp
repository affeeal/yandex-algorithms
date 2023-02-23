#include <algorithm>
#include <iostream>

int main()
{
	int N;
	std::cin >> N;
	int * letters = new int[N];
	for (auto i = 0; i < N; i++)
		std::cin >> letters[i];
	auto max_goodness = 0;
	for (auto i = 0; i < N - 1; i++)
		max_goodness += std::min(letters[i], letters[i + 1]);
	std::cout << max_goodness << std::endl;
	delete [] letters;
	return 0;
}
