#include <iostream>
#include <type_traits>


int main()
{
	int n = 10;

//	n + 1 = 10;
//	(n = 10) = 20;
//	++n = 10;		// ok,,  ++n 은 lvalue
//	n++ = 10;		// error. n++은 rvalue

	// decltype(exp) 규칙 2. exp 가 lvalue 라면 lvalue reference 타입이다.

	if ( std::is_lvalue_reference_v< decltype(( n )) > )
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;
}