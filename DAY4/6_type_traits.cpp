// 4_type_traits - 184page
#include <iostream>

// type traits : 타입 T에 대한 다양한 특성(특질)을 조사하는 기술

template<typename T> void printv(const T& v)
{
	if ( T 가 포인터 타입이면 )
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

