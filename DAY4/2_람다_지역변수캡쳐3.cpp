// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// [v1, v2] : capture by value
	// auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	// [&v1, &v2] : capture by reference
	auto f2 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f2(30); // v1=100 인데. 이때 v1 은 main 의 지역변수에 대한 별명이므로
			// 지역변수 v1도 수정됨.

	std::cout << v1 << std::endl;

	std::cout << sizeof(f2) << std::endl; // 8





	/*
	// 지역변수를 캡쳐했을때 원리
	// 컴파일러가 생성하는 클래스
	class CompilerGeneratedName
	{
		int& v1; // 캡쳐된 지역변수의 값을 보관하기 위한
		int& v2; // 멤버 데이타
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100;	// 참조변수인 v1 자체를 수정하는 표기법 아님.
						// v1이 가리키는 변수의 값을 수정한것
						// 그래서, const 멤버함수에서도 문제 없음.

			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName(v1, v2);
	*/
}





