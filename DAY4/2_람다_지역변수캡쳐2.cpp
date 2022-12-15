// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;
	// 아래코드가 에러인 이유
	// => 람다표현식을 보고 컴파일러가 만드는 operator() 는 상수 멤버함수입니다.
	// => 상수 멤버 함수 안에서 "v1=100" 을 할수 없으므로 에러!
	//auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 


	// mutable 람다 표현식
	// => operator() 함수를 non-const 멤버 함수로 해달라는 지시어
	auto f2 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	f2(30); // 이순간 "v1 = 100" 이 실행되는데..
			// 여기서 v1은 지역변수는 아니고, 복사본 입니다.

	std::cout << v1 << std::endl;

	std::cout << sizeof(f2) << std::endl; // 8





	/*
	// 지역변수를 캡쳐했을때 원리
	// 컴파일러가 생성하는 클래스
	class CompilerGeneratedName
	{
		int v1; // 캡쳐된 지역변수의 값을 보관하기 위한
		int v2; // 멤버 데이타
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) //const
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName(v1, v2);
	*/
}





