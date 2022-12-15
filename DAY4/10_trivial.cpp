#include <iostream>
#include <type_traits>

// Trivial : 하는일이 "자명하다" 는 의미의 단어
//			 => 특별 함수를 사용자가 만들지 않고
//           => 컴파일러가 만들어준 특별 함수가 하는일이 널리 알려진 대로 동작한다.
// 
// Trivial Constructor : 생성자가 하는 일이 없다!
// Trivial Destructor  : 소멸자가 하는 일이 없다!
// Trivial Copy Constructor  : 모든 멤버를 얕은 복사 할때.

class A {};

class B 
{
public:
	virtual void foo() {}
};

int main()
{
	// B의 생성자는 trivial 할까요 ?
}