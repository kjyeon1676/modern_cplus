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
		//=> 이미 r2의 타입이 int&& 인데, 다시 int&& 로 캐스팅하는 것은
		//   아무 의미 없지 않나요 ?
		//=> 이 코드는 "타입 캐스팅"이 아닌 "value 의 속성을 변경하는 캐스팅"
		//   이라고 정의 되어 있습니다.
		//   lvalue => rvalue 로 변경할때 사용합니다.
	

}







