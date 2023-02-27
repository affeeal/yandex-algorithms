#include <iostream>
#include <string>

#define INITIAL_CAPACITY 32

template <typename T>
struct Response
{
	bool is_successful;
	T value;
};

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	
	void push(T);
	Response<T> pop();
	Response<T> front();
	int get_size();
	void clear();
private:
	T* data;
	int head;
	int tail;
	int size;
	int capacity;
};

template <typename T>
Queue<T>::Queue()
	: head(0), tail(0), size(0), capacity(INITIAL_CAPACITY)
{
	data = new T[INITIAL_CAPACITY];
}

template <typename T>
Queue<T>::~Queue()
{
	delete[] data;
}

template <typename T>
void Queue<T>::push(T value)
{
	if (size == capacity)
	{
		T* new_data = new T[capacity << 1];
		for (int i = 0; i < tail; i++)
			new_data[i] = data[i];
		for (int i = capacity - 1; i >= head; i--)
			new_data[i + capacity] = data[i];
		delete[] data;
		data = new_data;
		head += capacity;
		capacity <<= 1;
	}
	data[tail++] = value;
	if (tail == capacity)
		tail = 0;
	size++;
}

template <typename T>
Response<T> Queue<T>::pop()
{
	if (size == 0)
		return Response<T> {false};
	T value = data[head++];
	if (head == capacity)
		head = 0;
	size--;
	return Response<T> {true, value};
}

template <typename T>
Response<T> Queue<T>::front()
{
	if (size == 0)
		return Response<T> {false};
	return Response<T> {true, data[head]};
}

template <typename T>
int Queue<T>::get_size()
{
	return size;
}

template <typename T>
void Queue<T>::clear()
{
	size = 0;
	tail = head;
}

int main()
{
	Queue<int> queue;
	while (true)
	{
		std::string command;
		std::cin >> command;
		if (command == "push")
		{
			int value;
			std::cin >> value;
			queue.push(value);
			std::cout << "ok" << std::endl;
		}
		else if (command == "pop")
		{
			Response<int> response = queue.pop();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "front")
		{
			Response<int> response = queue.front();
			if (response.is_successful)
				std::cout << response.value << std::endl;
			else
				std::cout << "error" << std::endl;
		}
		else if (command == "size")
		{
			std::cout << queue.get_size() << std::endl;
		}
		else if (command == "clear")
		{
			queue.clear();
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
