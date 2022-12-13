#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// 1번 호출, 없으면 2번 호출
	foo(10);	// 3번 호출, 없으면 2번 호출

	int& r1 = n;
	foo(r1);	// 1번 호출, 없으면 2번. 


	int&& r2 = 10;	// 이 한줄에서 "10" 은 rvalue
					// r2는 lvalue 입니다.
					// 
	// 데이타 타입과 value 속성을 헷갈리지 마세요
	//			타입			value 속성
	// n		int			lvalue
	// 10		int			rvalue
	// r1		int&		lvalue
	// r2		int&&		lvalue

	// foo(int&)  : 함수인자로 lvalue 를 받겠다는의미
	// foo(int&&) : 함수인자로 rvalue 를 받겠다는의미
	//			    함수 인자로 "int&&" 타입을 받겠다는 것이 아닙니다.

	foo(r2);					// foo(int&)  r2는 lvalue  이므로
	foo(static_cast<int&&>(r2));// foo(int&&) r2를 rvalue 로 캐스팅
}







