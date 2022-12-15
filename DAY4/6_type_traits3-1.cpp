// 6_type_traits3-1.     1번 복사해오세요.
#include <iostream>

template<typename T> void printv(const T& v)
{
	if (T 가 포인터 타입이면)
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


