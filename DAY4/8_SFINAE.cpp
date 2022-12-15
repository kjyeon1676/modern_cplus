// 5_SFINAE - 
#include <iostream>

// 핵심 : 아래처럼 3개의 함수가 있을때
//        함수 찾는 순서 알아두세요!!

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. int 호출. - exactly matching 
			// 2. T 사용 - template 을 사용하면 foo(int)를 
			//			생성할수 있으므로
			// 3. ... 사용
}