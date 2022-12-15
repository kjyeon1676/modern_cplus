// 6_람다_지역변수캡쳐1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// 1. 람다표현식에서 전역변수
	// => 전역변수는 프로그램에 어디서도 접근가능하다.
	// => 따라서, 람다표현식에서도 사용가능. 
	auto f1 = [](int a) { return a + g; };
				// class xxx{ operator() { a+g;}}; xxx();

	// 2. 람다표현식에서 main 함수 지역변수 접근
	// => main 함수 지역변수는 main 함수만 접근 가능!!
	auto f2 = [](int a) { return a + v1 + v2; }; // error


	// 3. 람다표현식에서 main 함수 지역변수 접근하려면 캡쳐해야 합니다.
	auto f3 = [v1, v2](int a) { return a + v1 + v2; };

	// 4. 값으로 캡쳐된 지역변수는 수정할수 없다.
	auto f4 = [v1, v2](int a) { v1 = 100; }; // error
}





