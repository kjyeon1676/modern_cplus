// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : Parameter pack ��� ��ҿ�
//				     ���� ������ ���� - C++17
// => �ݵ�� (  ) �� �ʿ� �մϴ�.

// unary right fold  : (pack�̸� op   ... )    : (E1 op ( E2 op E3) )
// unary left  fold  : (...     op  pack�̸� ) : ((E1 op E2) op E3 )

// binary right fold : (pack�̸� op   ... op  I )        : (E1 op ( E2 op ( E3 op I) ) )
// binary right fold : (I        op  ... op  pack �̸� ) : (((I op E1) op E2) op E3) )

template<typename ... Types> 
int Sum(Types ... args)
{
//	int s = (args + ...);     // (1 + ( 2 + 3) )

	int s = (args + ... + 0); // (1 + ( 2 + ( 3 + 0) )

	return s;
}

int main()
{
	int n = Sum();
//	int n = Sum(1, 2, 3);

	std::cout << n << std::endl;
}



