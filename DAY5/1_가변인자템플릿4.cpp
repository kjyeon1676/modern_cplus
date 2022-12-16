#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
//	printv(args...);	// printv(1, 2, 3) 이므로 에러

//	printv(args)...; // 의도 : printv(1), printv(2), printv(3) 
					 // error.

	// 핵심 1. pack expansion 은 가능한 위치가 정해져 있습니다.
	// 1. 함수 호출의 () 안
	// 2. {} 초기화 안 

	int x[] = { printv(args)... };
			//{ printv(E1), printv(E2), printv(E3) };
}




int main()
{
	foo(1, 2, 3);
}

