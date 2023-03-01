#include <iostream>
#include <vector>
#include <string>

struct Response
{
	bool is_successful;
	char value;
};

class Stack
{
public:
	void push(char);
	Response pop();
	bool is_empty();
private:
	std::vector<char> values;
};

void Stack::push(char value)
{
	values.push_back(value);
}

Response Stack::pop()
{
	if (values.empty())
		return Response {false};
	char value = values.back();
	values.pop_back();
	return Response {true, value};
}

bool Stack::is_empty()
{
	return values.empty();
}

int main()
{
	std::string brackets;
	std::cin >> brackets;
	Stack stack;
	bool is_valid = true;
	for (const auto& bracket : brackets)
	{
		if (bracket == '(' || bracket == '[' || bracket == '{')
		{
			stack.push(bracket);
			continue;
		}
		char opening_bracket = 
			bracket == ')' ? '(' :
			bracket == ']' ? '[' :'{';
		Response response = stack.pop();
		if (response.is_successful == false || response.value != opening_bracket)
		{
			is_valid = false;
			break;
		}
	}
	if (is_valid && stack.is_empty())
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;;
	return 0;
}
