// 9_FOLD - 237 page

#include <iostream>

// Fold Expression : Parameter pack 모든 요소에
//				     이항 연산을 수행 - C++17
// => 반드시 (  ) 가 필요 합니다.

// unary right fold  : (pack이름 op   ... )    : (E1 op ( E2 op E3) )
// unary left  fold  : (...     op  pack이름 ) : ((E1 op E2) op E3 )

// binary right fold : (pack이름 op   ... op  I )        : (E1 op ( E2 op ( E3 op I) ) )
// binary right fold : (I        op  ... op  pack 이름 ) : (((I op E1) op E2) op E3) )

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



