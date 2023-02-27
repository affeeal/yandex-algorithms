#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
	void push(T);
	T pop();
	T back();
	bool is_empty();
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
bool Stack<T>::is_empty()
{
	return values.empty();
}

int main()
{
	int N;
	std::cin >> N;
	Stack<int> stack;
	int desired_van = 1;
	for (auto i = 0; i < N; i++)
	{
		int van;
		std::cin >> van;
		if (desired_van == van)
		{
			desired_van++;
			while (!stack.is_empty() && stack.back() == desired_van)
			{
				stack.pop();
				desired_van++;
			}
		}
		else
			stack.push(van);
	}
	if (stack.is_empty())
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return 0;
}
