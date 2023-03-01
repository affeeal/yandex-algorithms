#include <iostream>
#include <vector>
#include <string>

class Stack
{
public:
	void push(int);
	int pop();
private:
	std::vector<int> values;
};

void Stack::push(int value)
{
	values.push_back(value);
}

int Stack::pop()
{
	int value = values.back();
	values.pop_back();
	return value;
}

int main()
{
	Stack stack;
	std::string input_line;
	std::getline(std::cin, input_line);
	for (const auto& symbol : input_line)
	{
		if ('0' <= symbol && symbol <= '9')
		{
			stack.push(symbol - '0');
		}
		else if (symbol == '+')
		{
			int b = stack.pop();
			int a = stack.pop();
			stack.push(a + b);
		}
		else if (symbol == '-')
		{
			int b = stack.pop();
			int a = stack.pop();
			stack.push(a - b);
		}
		else if (symbol == '*')
		{
			int b = stack.pop();
			int a = stack.pop();
			stack.push(a * b);
		}
	}
	std::cout << stack.pop() << std::endl;
	return 0;
}
