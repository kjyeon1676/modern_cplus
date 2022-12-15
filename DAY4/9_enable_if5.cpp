// printv 복사 -  traits3-1 복사
#include <iostream>
#include <type_traits>

// T 가 포인터 여부에 따라 구현을 다르게 작성하는 방법
// 1. C++17 버전 : if constexpr
/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

// 2. C++11 버전 : std::enable_if 사용

template<typename T> 
std::enable_if_t< std::is_pointer_v<T> > 
printv(const T& v)
{
	std::cout << v << " : " << *v << std::endl;
}

template<typename T> 
std::enable_if_t< !std::is_pointer_v<T> >
printv(const T& v)
{
	std::cout << v << std::endl;
}


int main()
{
	int n = 10;

	printv(n);
	printv(&n);// ok.

}


