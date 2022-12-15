// printv ���� -  traits3-1 ����
#include <iostream>
#include <type_traits>

// T �� ������ ���ο� ���� ������ �ٸ��� �ۼ��ϴ� ���
// 1. C++17 ���� : if constexpr
/*
template<typename T> void printv(const T& v)
{
	if constexpr (std::is_pointer<T>::value)
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}
*/

// 2. C++11 ���� : std::enable_if ���

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


