#include <cstddef>
#include <iostream>
#include <vector>
#include <string>

struct Response
{
	bool ok;
	int value;
};

class Stack
{
public:
	void push(int);
	Response pop();
	Response back();
	size_t size();
	void clear();
	
	static const std::string command_push;
	static const std::string command_pop;
	static const std::string command_back;
	static const std::string command_size;
	static const std::string command_clear;
	static const std::string command_exit;
private:
	std::vector<int> values;
};

void Stack::push(int value)
{
	values.push_back(value);
}

Response Stack::pop()
{
	if (values.empty())
		return Response {false};
	int value = values.back();
	values.pop_back();
	return Response {true, value};
}

Response Stack::back()
{
	if (values.empty())
		return Response {false};
	return Response {true, values.back()};
}

size_t Stack::size()
{
	return values.size();
}

void Stack::clear()
{
	values.clear();
}

const std::string Stack::command_push = "push";
const std::string Stack::command_pop = "pop";
const std::string Stack::command_back = "back";
const std::string Stack::command_size = "size";
const std::string Stack::command_clear = "clear";
const std::string Stack::command_exit = "exit";

int main()
{
	Stack stack;
	while(true)
	{
		std::string command;
		std::cin >> command;
		if (command == Stack::command_push)
		{
			int value;
			std::cin >> value;
			stack.push(value);
			std::cout << "ok" << std::endl;
		}
		else if (command == Stack::command_pop)
		{
			Response response = stack.pop();
			if (response.ok)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == Stack::command_back)
		{
			Response response = stack.back();
			if (response.ok)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == Stack::command_size)
		{
			std::cout << stack.size() << std::endl;
		}
		else if (command == Stack::command_clear)
		{
			stack.clear();
			std::cout << "ok" << std::endl;
		}
		else if (command == Stack::command_exit)
		{
			std::cout << "bye" << std::endl;
			break;
		}
	}
	return 0;
}
