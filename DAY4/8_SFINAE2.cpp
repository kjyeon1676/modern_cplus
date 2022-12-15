#include <iostream>

// SFINAE
// => Substitution Failure Is Not An Error
// 
// => 함수 템플릿을 사용하기로 결정했는데...
//    T의 타입을 결정하고 실제 함수를 만들다가 실패 했다면
//    컴파일 에러가 아니라, 함수의 후보군에서 제외 된다는 의미..!!

// => 동일 이름의 다른 함수가 있다면 사용될수 있다.

template<typename T>
typename T::type foo(T a) { std::cout << "T" << std::endl; return 0; }
//     int::type foo(int a) { .... } 의 모양을 생성하려고 한다

int foo(...) { std::cout << "..." << std::endl; return 0; }

int main()
{
	foo(3); 
}