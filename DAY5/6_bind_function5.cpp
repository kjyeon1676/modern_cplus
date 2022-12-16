#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int& b) { b = 100; }

int main()
{	
	std::function<void(int)> f;

	int n = 0;

//	f = std::bind(&foo, _1, n);  // 이 한줄을 생각 해 봅시다.
								// 1. n 이라는 변수가 고정될까요 ?
								// 2. n 의 값이 고정될까요 ?
								// => 답은 2번, n의 값을 보관하고 있다가 사용

	f = std::bind(&foo, _1, std::ref(n) ); // n의 값을 고정하지 말고
								// n 자체를 참조로 고정해 달라

	f(0); // foo(0, n)

	std::cout << n << std::endl; // 결과 예측해 보세요
}


