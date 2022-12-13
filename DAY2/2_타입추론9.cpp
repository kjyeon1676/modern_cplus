#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4); // auto는 우변의 참조를
//  int  ret = foo(1, 3.4); // 제거하고 타입 결정

	// decltype(함수호출식) : 함수 호출의 결과로 나오는 타입
	//						 함수 선언을 보고 조사
	//						 "함수 호출식"이 실제 실행되는 것은 아님
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//	int&	ret2 = foo(1, 3.4);

	// decltype(auto) : C++14 부터 지원
	// => auto 자리에 우변 표현식을 넣어 달라.
	// => 또는 우변으로 표현식으로 타입을 추론하는 데, 
	//    규칙은 decltype 규칙 사용

	decltype(auto) ret3 = foo(1, 3.4);
//	int&	ret3 = foo(1, 3.4);
}