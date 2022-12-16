// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : Parameter pack ��� ��ҿ�
//				     ���� ������ ���� - C++17
// => �ݵ�� (  ) �� �ʿ� �մϴ�.

// (pack�̸�   op   ... ) : (E1 op ( E2 op E3) )


template<typename ... Types> 
int Sum(Types ... args)
{
	int s = (args + ...); // (1 + ( 2 + 3) )

	return s;
}
int main()
{
	int n = Sum(1, 2, 3);

	std::cout << n << std::endl;
}



