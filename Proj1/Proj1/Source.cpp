#include <thread>
#include <iostream>

class thread_guard
{
	std::thread& t;
public:
	explicit thread_guard(std::thread& t_) :
		t(t_)
	{}
	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
			std::cout << "join\n" ;
		}
	}

	thread_guard(thread_guard const&) = delete;				// Копирующий конструктор и копирующий оператор присваивания помечены признаком =delete, 
															// чтобы компилятор не генерировал их автоматически: копирование или присваивание такого объекта таит в себе опасность 
	thread_guard& operator=(thread_guard const&) = delete;	// поскольку время жизни копии может оказаться дольше, чем время жизни присоединяемого потока.
	
};

void do_something(int& i)
{
	++i;
}

struct func
{
	int& i;

	func(int& i_) :i(i_) {
	
	}

	void operator()()
	{
		for (unsigned j = 0; j < 10000000; ++j)
		{
			do_something(i);
			if (i % 1000000 == 0) std::cout << i << "\n";
		}
	}
};

void do_something_in_current_thread()
{}


void f()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread t(my_func);
	thread_guard g(t);

	do_something_in_current_thread();

	std::cout << "close\n";
}

int main()
{
	f();
}
