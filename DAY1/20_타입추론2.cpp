#include <iostream>
// 규칙 1. 템플릿 파라미터가 "값(T a)" 타입 일때
// => 함수 인자가 가진 "const, volatilie, reference" 속성을 제거
//    하고 T의 타입을 결정한다.
template<typename T> void foo(T a)
{
	// 확인하는 방법 1. C++ 표준 rtti 기술 사용
	std::cout << typeid(T).name() << std::endl;

	a = 100;
}

int main()
{
	// 사용자가 타입전달
	// => 컴파일러는 타입을 추론할 필요 없음. 무조건 사용자가 전달한 타입사용
	foo<int>(3);

	// 타입을 전달하지 않으면 함수 인자를 보고 타입을 추론합니다.
	foo(10); // T=int
	foo(3.4);// T=double


	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T=int
	foo(c);		// T=int
	foo(r);		// T=int
	foo(cr);	// T=int
}