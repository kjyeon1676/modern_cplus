#include <iostream>

// 규칙 2. 템플릿 파라미터가 "참조(T&)" 타입일때
// => 인자가 가진 reference 속성만 제거후 T의 타입을 결정
// => const, volatile 은 유지 한다.
// => T의 타입 결정후 & 를 붙이면 a의 타입.
template<typename T> void foo(T& a)
{
	std::cout << __FUNCSIG__ << std::endl;
}

int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	foo(n);  // T=int,			a=int&
	foo(c);  // T=const int,	a=const int&
	foo(r);  // T=int			a=int&
	foo(cr); // T=const int		a=const int&
}