// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : Parameter pack 모든 요소에
//				     이항 연산을 수행 - C++17
// => 반드시 (  ) 가 필요 합니다.

// (pack이름   op   ... ) : (E1 op ( E2 op E3) )


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



