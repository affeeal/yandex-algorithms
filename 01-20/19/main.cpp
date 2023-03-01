#include <iostream>
#include <vector>

class Heap
{
public:
	void insert(int);
	int extract();
private:
	std::vector<int> data;
};

void Heap::insert(int number)
{
	data.push_back(number);
	int i = data.size() - 1;
	while (true)
	{
		auto parent = (i - 1) >> 1;
		if (parent < 0 || data[parent] >= data[i])
			break;
		auto t = data[parent];
		data[parent] = data[i];
		data[i] = t;
		i = parent;
	}
}

int Heap::extract()
{
	auto number = data.front();
	data.front() = data.back();
	data.pop_back();
	auto i = 0;
	while (true)
	{
		auto left = (i << 1) + 1;
		auto right = left + 1;
		if (right < data.size()) 
		{
			auto max_index = data[left] > data[right] ? left : right;
			if (data[i] < data[max_index])
			{
				auto t = data[max_index];
				data[max_index] = data[i];
				data[i] = t;
				i = max_index;
			}
			else
				break;
		}
		else if (left < data.size() && data[i] < data[left])
		{
			auto t = data[left];
			data[left] = data[i];
			data[i] = t;
			i = left;
		}
		else
			break;
	}
	return number;
}

int main()
{
	int N;
	std::cin >> N;
	Heap heap;
	for (auto i = 0; i < N; i++)
	{
		int command;
		std::cin >> command;
		if (command == 0)
		{
			int number;
			std::cin >> number;
			heap.insert(number);
		}
		else if (command == 1)
		{
			std::cout << heap.extract() << std::endl;
		}
	}
	return 0;
}
