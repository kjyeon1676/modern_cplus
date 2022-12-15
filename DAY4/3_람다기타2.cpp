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

	std::cout << f1(1, 2) << std::endl;		// operator(int, int)생성
	std::cout << f1(1.1, 2.1) << std::endl; // operator(double, double)생성
	std::cout << f1(1,   2.1) << std::endl; // operator(int, double)생성
	std::cout << f1(1.1, 2 ) << std::endl;
}

// generic 람다 표현식의 원리 
// => operator() 가 함수 템플릿으로 만들어 지는것
// => 2개의 인자가 서로 다른 템플릿 파라미터 사용
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	inline auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};