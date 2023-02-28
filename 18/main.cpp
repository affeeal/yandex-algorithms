#include <iostream>
#include <string>

struct Response
{
	bool is_successful;
	int value;
};

class Dequeue
{
public:
	Dequeue();
	~Dequeue();

	void push_front(int);
	void push_back(int);
	Response pop_front();
	Response pop_back();
	Response front();
	Response back();
	int get_count();
	void clear();
private:
	int* data;
	int head;
	int tail;
	int count;
	static const int capacity;
};

Dequeue::Dequeue()
{
	data = new int[capacity];
	head = capacity / 2;
	tail = head - 1;
	count = 0;
}

Dequeue::~Dequeue()
{
	delete[] data;
}

void Dequeue::push_front(int value)
{
	if (head == 0)
		head = capacity;
	data[--head] = value;
	count++;
}

void Dequeue::push_back(int value)
{
	if (tail == capacity - 1)
		tail = -1;
	data[++tail] =value;
	count++;
}

Response Dequeue::pop_front()
{
	if (count == 0)
		return Response {false};
	int value = data[head++];
	if (head == capacity)
		head = 0;
	count--;
	return Response {true, value};
}

Response Dequeue::pop_back()
{
	if (count == 0)
		return Response {false};
	int value = data[tail--];
	if (tail == -1)
		tail = capacity - 1;
	count--;
	return Response {true, value};
}

Response Dequeue::front()
{
	if (count == 0)
		return Response {false};
	return Response {true, data[head]};
}

Response Dequeue::back()
{
	if (count == 0)
		return Response {false};
	return Response {true, data[tail]};
}

int Dequeue::get_count()
{
	return count;
}

void Dequeue::clear()
{
	head = capacity / 2;
	tail = head - 1;
	count = 0;
}

const int Dequeue::capacity = 100;

int main()
{
	Dequeue dequeue;
	while (true)
	{
		std::string command;
		std::cin >> command;
		if (command == "push_front")
		{
			int value;
			std::cin >> value;
			dequeue.push_front(value);
			std::cout << "ok" << std::endl;
		}
		else if (command == "push_back")
		{
			int value;
			std::cin >> value;
			dequeue.push_back(value);
			std::cout << "ok" << std::endl;
		}
		else if (command == "pop_front")
		{
			Response response = dequeue.pop_front();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "pop_back")
		{
			Response response = dequeue.pop_back();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "front")
		{
			Response response = dequeue.front();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "back")
		{
			Response response = dequeue.back();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "size")
		{
			std::cout << dequeue.get_count() << std::endl;
		}
		else if (command == "clear")
		{
			dequeue.clear();
			std::cout << "ok" << std::endl;
		}
		else if (command == "exit")
		{
			std::cout << "bye" << std::endl;
			break;
		}
	}
	return 0;
}
