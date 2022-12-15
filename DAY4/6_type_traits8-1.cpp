#include <iostream>
#include <type_traits>
#include <vector>

#define PRINT_VALUE_CATEGORY(...)									\
	if (std::is_lvalue_reference_v< decltype(( __VA_ARGS__ )) >)	\
		std::cout << "lvalue" << std::endl;							\
	else                                                            \
		std::cout << "rvalue" << std::endl;

int main()
{
	int n = 10;
	
	PRINT_VALUE_CATEGORY(n);	// lvalue
	PRINT_VALUE_CATEGORY(++n);	// lvalue
	PRINT_VALUE_CATEGORY(n+1);	// rvalue
	PRINT_VALUE_CATEGORY(3.4);	// rvalue
	PRINT_VALUE_CATEGORY(10);	// rvalue
	PRINT_VALUE_CATEGORY(std::vector<int>{1, 2, 3});// rvalue
	PRINT_VALUE_CATEGORY("hello"); // lvalue 

	// C++ ���� ���ڿ� literal �� lvalue �� ��� �˴ϴ�.
//	"hello"[0] = 'A'; // error. �� rvalue �� ������ �ƴ�
					  //        ����� ���� �Դϴ�.
}