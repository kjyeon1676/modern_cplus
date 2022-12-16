// 7_가변인자템플릿7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// 가변인자 템플릿은 
// => 사용하는 전형적인 스타일이 있습니다.
// => 아래 코드는 함수와 함수에 보낼 인자 한개만 받아서 전달합니다.
/*
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}
*/

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f( std::forward<Types>(arg)... );
		// f( std::forward<Types>(E1), 
		//    std::forward<Types>(E2)
		//    std::forward<Types>(E3))
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

