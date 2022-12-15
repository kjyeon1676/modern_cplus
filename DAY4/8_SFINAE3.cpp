#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

// 아래 코드는 SFINAE 가 적용될까요 ?
// => 적용되지 않습니다
// => error 입니다.
/*
template<typename T>
int foo(T arg)
{
	typedef T::type n; // ?
	 
	return 0;
}
*/
// SFINAE 는 함수 signature 가 실패 할때만 적용됩니다.

// 1. 리턴 타입 - 가장 널리 사용
// template<typename T>
//typename T::type foo(T arg) { return  0; }

// 2. 함수 인자 타입
//template<typename T>
//int foo(T arg, typename T::type arg2 = 0 ) { return  0; }


// 3. 템플릿 인자 타입 
// => 생성자는 반환 타입이 없는데..
// => 생성자에서 "SFINAE" 기술을 사용할때 널리 사용

template<typename T, typename T2 = typename T::type>
int foo(T arg ) { return  0; }

int main()
{
	foo(3);
}