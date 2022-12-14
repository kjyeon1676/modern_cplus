// 9_완벽한전달_주의사항
#include <iostream>

// 완벽한 전달을 사용하는 모든 도구들
// => chronometry, 
// => emplace_back
// => make_shared 등을 사용할때는 포인터 의미의 0은 사용하지 마세요
// => 반드시 nullptr 을 사용하세요..



template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0
{								// foo(arg) 는 에러!
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok
	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // error

}









