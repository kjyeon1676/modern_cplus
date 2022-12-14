// 9_완벽한전달_주의사항
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// 함수를 직접 호출시
	// => 인자를 보고 어느 함수인지 찾을수 있다.
	foo();
	foo(10);
	foo(10, 20);
 
//	chronometry(foo, 10); // error

	// 컴파일러가 여러개의 foo 중에서 어떤 함수인지를
	// 구별할수 있도록 힌트를 전달해야 합니다.(캐스팅 같은 코드)
	chronometry(static_cast<void(*)(int)>(foo), 10);
}









