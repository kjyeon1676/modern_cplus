#include <iostream>
#include <type_traits>

#define PRINT_VALUE_CATEGORY(...)									\
	if (std::is_lvalue_reference_v< decltype(( __VA_ARGS__ )) >)	\
		std::cout << "lvalue" << std::endl;							\
	else                                                            \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;
	
	PRINT_VALUE_CATEGORY(n);
	PRINT_VALUE_CATEGORY(++n);
	PRINT_VALUE_CATEGORY(n+1);
	PRINT_VALUE_CATEGORY(3.4);
	PRINT_VALUE_CATEGORY(10);
	PRINT_VALUE_CATEGORY("hello"); //!!!


}