#include <iostream>

// 함수 인자로 auto 사용은 "C++20" 부터 지원 합니다.
// void foo(auto n) {} 


int main()
{
	// generic lambda
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // 에러는 아니지만
							// 결과가 6
	
	// 핵심 1. Generic lambda
	// => C++14 부터 람다 표현식의 인자로 auto 사용가능합니다
	// => 일반함수는 C++20 부터 인자로 auto 사용가능합니다.
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1, 2) << std::endl;
	std::cout << f1(1.1, 2.1) << std::endl;
	std::cout << f1(1,   2.1) << std::endl;
	std::cout << f1(1.1, 2 ) << std::endl;
}