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

	// args 의 요소 갯수가 0인 경우를 대비해서
	// 1. 제일 앞에 더미 0을 주거나 
	//int x[] = { 0, (printv(args), 0)... }; 
			//{ (printv(E1), 0), (printv(E2),0), (printv(E3), 0) };
			// {}

	// 2. 
	std::initializer_list<int> e = { (printv(args), 0)... };
}

int main()
{
//	foo();
	foo(1, 2, 3);
}

