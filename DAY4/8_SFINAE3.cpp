#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

// 아래 코드는 SFINAE 가 적용될까요 ?
template<typename T>
int foo(T arg)
{
	typedef T::type n; // ?
	 
	return 0;
}

int main()
{
	foo(3);
}