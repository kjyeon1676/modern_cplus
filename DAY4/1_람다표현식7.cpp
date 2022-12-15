// 145 page
#include <iostream>
int main()
{
	// 람다표현식의 정확한 모양
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 1. return 문장이 한개라면 리턴 타입은 생략가능합니다.
	auto f2 = [](int a, int b) { return a + b; };

	// 2. return 문장이 여러개 라도 같은 타입을 반환하면 생략가능합니다.
	auto f3 = [](int a, int b) { if (a == 1) return a; return b; };

	// 3. return 문장이 여러개 인데, 다른 타입을 반환하는 경우
	//    반드시 리턴 타입을 명시적으로 표기해야 합니다.
	//    아래 코드는 에러
	auto f4 = [](int a, double b) { if (a == 1) return a; return b; }; 

	// 아래 처럼 표기해야 합니다.
	auto f4 = [](int a, double b)-> double { if (a == 1) return a; return b; };
}

