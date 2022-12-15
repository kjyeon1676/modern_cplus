// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// 지역변수를 캡쳐했을때 원리
	// 컴파일러가 생성하는 클래스
	class CompilerGeneratedName
	{
		int v1; // 캡쳐된 지역변수의 값을 보관하기 위한
		int v2; // 멤버 데이타
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName(v1, v2);
}





