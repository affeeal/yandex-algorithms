#include <iostream>
#include <vector>

// TODO: реализовать бинарный поиск для получения сложности O(N*log(N))

struct Segment
{
	int a;
	int b;
	bool is_present;
};

int main()
{
	int M, N;
	std::cin >> M >> N;
	std::vector<Segment> segments;
	int count = 0;
	for (auto i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a >> b;

		for (auto& segment : segments)
			if (segment.is_present && segment.a <= b && segment.b >= a)
			{
				segment.is_present = false;
				count--;
			}
		segments.push_back(Segment { a, b, true });
		count++;
	}
	std::cout << count << std::endl;
	return 0;
}
