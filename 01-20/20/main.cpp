#include <iostream>
#include <vector>

class Heap
{
public:
	void push_back(int);
	void sort();
	void print();
private:
	std::vector<int> data;

	void heapify(int, int);
	void build_heap(int);
};

void Heap::push_back(int number)
{
	data.push_back(number);
}
void Heap::sort()
{
	build_heap(data.size());
	auto i = data.size() - 1;
	while (i > 0)
	{
		auto t = data[0];
		data[0] = data[i];
		data[i] = t;
		heapify(0, i);
		i--;
	}
}

void Heap::print()
{
	for (const auto& number : data)
		std::cout << number << ' ';
	std::cout << std::endl;
}

void Heap::build_heap(int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		heapify(i, n);
		i--;
	}
}

void Heap::heapify(int i, int count)
{
	while (true)
	{
		auto j = i;
		auto left = (i << 1) + 1;
		auto right = left + 1;
		if (left < count && data[left] > data[i])
			i = left;
		if (right < count && data[right] > data[i])
			i = right;
		if (i == j)
			break;
		auto t = data[i];
		data[i] = data[j];
		data[j] = t;
	}
}

int main()
{
	int N;
	std::cin >> N;
	Heap heap;
	for (auto i = 0; i < N; i++)
	{
		int number;
		std::cin >> number;
		heap.push_back(number);
	}
	heap.sort();
	heap.print();
	return 0;
}
