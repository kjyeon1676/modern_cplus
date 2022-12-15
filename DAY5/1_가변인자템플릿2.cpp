#include <iostream>

template<typename ... Types> 
void foo(Types ... args)
{
	// 핵심 1. "parameter pack" 이라는 용어 알아 두세요
	// Types : int, int, int	=> template parameter pack
	// args  : 1,   2,   3		=> function parameter pack

	// 핵심 2. sizeof... 알아 두세요
	std::cout << sizeof...(args)  << std::endl;
	std::cout << sizeof...(Types) << std::endl;

}

int main()
{
	foo(1, 2, 3); // foo(int, int, int) 함수가 생성
}