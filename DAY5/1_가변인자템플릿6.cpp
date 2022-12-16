#include <iostream>

// 233 page 입니다.

// 핵심 : 함수의 모든 인자를 가변인자로 하지 말고
//        1번째 인자를 독립적인 이름을 사용

void foo() {} // recursive 유사 코드의 종료를 위해서!!
				// C++14 까지는 이렇게 했습니다.
				// C++17 부터는 아래 main 처럼.. 

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	static int cnt = 0;
	++cnt;
	std::cout << value << " : " << cnt << std::endl; // cnt는 항상 1

	if constexpr (sizeof...(args) > 0)
		foo(args...);

//	foo(args...); // foo(3.4, 'A')
				  // foo('A');
				  // foo()
}

int main()
{
	foo(1, 3.4, 'A'); 
}





