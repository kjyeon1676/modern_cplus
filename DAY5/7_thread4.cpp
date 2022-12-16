#include <iostream>
#include <thread>
#include <future> 
#include <chrono>
using namespace std::chrono;
using namespace std::literals;

// promise & future

// 스레드를 고려하지 않은 일반 함수라면 반환 값으로 함수 결과를 돌려 줍니다.
// 그런데 아래 함수를 스레드로 수행후 결과를 꺼내 오려면
// 1. promise & future
// 2. async
int add1(int a, int b)
{
	int c = a + b; // 복잡한 연산

	return c;
}

int main()
{
	std::thread t(&add1, 1, 2);
						
	t.join();
}


