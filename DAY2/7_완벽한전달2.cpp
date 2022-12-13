// 7_완벽한전달1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// 완벽한 전달을 하려면
// 1. 복사본이 없어야 한다.
// 2. const 속성이 추가되어도 안된다.

// 해결책 : int&, int&& 버전을 따로 제공해야 한다!

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);	
}

template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
