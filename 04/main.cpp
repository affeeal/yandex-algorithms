#include <iostream>

int main()
{
	int N, K, petya_desk, petya_seat;
	std::cin >> N >> K >> petya_desk >> petya_seat;
	
	auto petya_number = 2 * (petya_desk - 1) + petya_seat;
	auto vasya_desk_back = 0;
	auto vasya_seat_back = 0;
	auto vasya_desk_front = 0;
	auto vasya_seat_front = 0;
	
	if (petya_number + K <= N)
	{
		vasya_desk_back = (petya_number + K + 1) / 2;
		vasya_seat_back = (petya_number + K) % 2 ? 1 : 2;
	}
	if (petya_number - K >= 1)
	{
		vasya_desk_front = (petya_number - K + 1) / 2;
		vasya_seat_front = (petya_number - K) % 2 ? 1 : 2;
	}
	
	if (vasya_desk_back && vasya_desk_front)
	{
		if (vasya_desk_back - petya_desk > petya_desk - vasya_desk_front)
			std::cout << vasya_desk_front << ' ' << vasya_seat_front << std::endl;
		else
			std::cout << vasya_desk_back << ' ' << vasya_seat_back << std::endl;
	}
	else if (!vasya_desk_back && vasya_desk_front)
		std::cout << vasya_desk_front << ' ' << vasya_seat_front << std::endl;
	else if (vasya_desk_back && !vasya_desk_front)
		std::cout << vasya_desk_back << ' ' << vasya_seat_back << std::endl;
	else 
		std::cout << -1 << std::endl;

	return 0;
}
