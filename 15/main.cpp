#include <iostream>
#include <vector>

struct Town
{
	unsigned int index;
	int price;
};

template <typename T>
class Stack
{
public:
	void push(T);
	T pop();
	T back();
	bool empty();
private:
	std::vector<T> values;
};

template <typename T>
void Stack<T>::push(T value)
{
	values.push_back(value);
}

template <typename T>
T Stack<T>::back()
{
	return values.back();
}

template <typename T>
T Stack<T>::pop()
{
	T value = back();
	values.pop_back();
	return value;
}

template <typename T>
bool Stack<T>::empty()
{
	return values.empty();
}

int main()
{
	unsigned int N;
	std::cin >> N;
	int* prices = new int[N];
	for (unsigned int i = 0; i < N; i++)
		std::cin >> prices[i];
	int* min_prices = new int[N];
	Stack<Town> stack;
	for (unsigned int i = 0; i < N; i++)
	{
		while (!stack.empty() && prices[i] < stack.back().price)
		{
			Town town = stack.pop();
			min_prices[town.index] = i;
		}
		stack.push(Town {i, prices[i]});
	}
	while (!stack.empty())
	{
		Town town = stack.pop();
		min_prices[town.index] = -1;
	}
	for (unsigned int i = 0; i < N; i++)
		std::cout << min_prices[i] << ' ';
	std::cout << std::endl;
	delete[] min_prices;
	delete[] prices;
	return 0;
}
