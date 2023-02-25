#include <iostream>

struct Coordinate
{
	int x;
	int y;
};

int main()
{
	int K;
	std::cin >> K;
	Coordinate lower_left, upper_right;
	bool initialized = false;
	for (auto i = 0; i < K; i++)
	{
		int x, y;
		std::cin >> x >> y;
		if (initialized == false)
		{
			lower_left = upper_right = {x, y};
			initialized = true;
		}
		else
		{
			lower_left.x  = x < lower_left.x  ? x : lower_left.x;
			upper_right.x = x > upper_right.x ? x : upper_right.x; 
			lower_left.y  = y < lower_left.y  ? y : lower_left.y;
			upper_right.y = y > upper_right.y ? y : upper_right.y;
		}
	}
	std::cout << lower_left.x  << ' ' << lower_left.y  << ' '
		      << upper_right.x << ' ' << upper_right.y << std::endl;
	return 0;
}
