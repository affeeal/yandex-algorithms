#include <iostream>
#include <queue>

#define LIMIT 1000000
#define N 5

int main()
{
	std::queue<int> first;
	for (auto i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;
		first.push(value);
	}
	std::queue<int> second;
	for (auto i = 0; i < N; i++)
	{
		int value;
		std::cin >> value;
		second.push(value);
	}
	int count = 0;
	while (!first.empty() && !second.empty())
	{
		if (first.front() > second.front() && (first.front() != 9 || second.front() != 0) ||
				first.front() == 0 && second.front() == 9)
		{
			first.push(first.front());
			first.pop();
			first.push(second.front());
			second.pop();
		}
		else if (first.front() < second.front() && (first.front() != 0 || second.front() != 9) ||
				first.front() == 9 && second.front() == 0)
		{
			second.push(first.front());
			first.pop();
			second.push(second.front());
			second.pop();
		}
		count++;
		if (count >= LIMIT)
			break;
	}
	if (first.empty())
		std::cout << "second" << ' ' << count << std::endl;
	else if (second.empty())
		std::cout << "first" << ' ' << count << std::endl;
	else
		std::cout << "botva" << std::endl;
	return 0;
}
