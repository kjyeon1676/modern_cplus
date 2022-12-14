#include <iostream>

// 함수객체와 const member function

struct Plus
{
	// 핵심 : 함수 객체 만들떄, () 연산자 함수는 보통
	//       상수 멤버 함수로 하는 것이 원칙 입니다.
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

template<typename T> void foo(const T& f)
{
	// 상수 객체는 상수 멤버 함수만 호출 가능합니다.
	// 현재 f가 상수 객체 이므로 
	// 아래 처럼 사용가능하려면, "operator()" 연산자함수를
	// 반드시 상수 멤버 함수로해야 합니다.

	int ret = f(1, 2); // f.operator()(1,2)
}

int main()
{
	Plus p;

	foo(p);
}
