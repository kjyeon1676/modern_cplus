#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	// 스레드를 생성하는 방법

	std::thread t1(&foo, 3, 3.4);

	// 스레드를 생성한 경우
	t1.join();   // 1. 종료를 대기하거나
//	t1.detach(); // 2. 자식스레드를 분리해야 합니다.

	// 모든 종류의 함수를 스레드로 수행할수 있습니다.
	Test test;
	std::thread t2(&Test::goo, &test, 1, 3.4);

	t2.join();
}


