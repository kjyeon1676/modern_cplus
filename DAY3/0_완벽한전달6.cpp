#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // 필요없는 캐스팅이지만
								 // 있어도 전혀 문제가 되지 않습니다.
}
template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// T=int	T&&=int&&	
							// chronometry(F, int&&) 생성
							// static_cast<int&&>(arg)

	chronometry(goo, n);	// T=int&		T&&=int&
							// chronometry(F, int&) 생성
							// static_cast<int&>(arg)
}
