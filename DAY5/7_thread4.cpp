#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// promise & future

int add1(int a, int b)
{
	int c = a + b; // ������ ����

	return c;
}

int main()
{
	std::thread t(&add1, 1, 2);
						
	t.join();
}


