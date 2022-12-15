// 6_type_traits3-1.     1번 복사해오세요.
#include <iostream>
#include <type_traits> // std::is_pointer<> 가 있습니다,

template<typename T> void printv(const T& v)
{
	if ( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}


