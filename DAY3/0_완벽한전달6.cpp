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
	// 아래 캐스팅은  chronometry 의 2번째 인자로

	// rvalue 를 보내면 rvalue 로 캐스팅하게 되고
	// lvluae 를 보내면 lvalue 로 캐스팅하게 됩니다.
	//f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) );	// 위 캐스팅과 동일한 일을 하는
								// C++ 표준 함수
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
