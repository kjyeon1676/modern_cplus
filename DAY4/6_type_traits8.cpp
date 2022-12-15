#include <iostream>
#include <type_traits>


int main()
{
	int n = 10;

//	n + 1 = 10;
//	(n = 10) = 20;
//	++n = 10;		// ok,,  ++n �� lvalue
//	n++ = 10;		// error. n++�� rvalue

	// decltype(exp) ��Ģ 2. exp �� lvalue ��� lvalue reference Ÿ���̴�.

	if ( std::is_lvalue_reference_v< decltype(( n )) > )
		std::cout << "lvalue" << std::endl;
	else 
		std::cout << "rvalue" << std::endl;
}