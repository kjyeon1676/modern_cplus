#include <iostream>
#include <type_traits>

// Trivial : 하는일이 "자명하다" 는 의미의 단어
//			 => 특별 함수를 사용자가 만들지 않고
//           => 컴파일러가 만들어준 특별 함수가 하는일이 널리 알려진 대로 동작한다.
// 
// "널리 알려진 대로" 라는 의미.
// Trivial Constructor : 생성자가 하는 일이 없다!
// Trivial Destructor  : 소멸자가 하는 일이 없다!
// Trivial Copy Constructor  : 모든 멤버를 얕은 복사 할때.

class A {};

class B : public A
{

public:
//	virtual void foo() {}
};

// 생성자가 trivial 하려면
// 1. 가상함수가 없고
// 2. 사용자가 만들 생성자가 없고
// 3. 객체형 멤버가 없거나 객체형 멤버의 생성자가 Trivial 하고.
// 4. 기반 클래스가 없거나 기반 클래스의 생성자가 Trivial 하고.
// 의 조건을 만족할때 생성자는 trivial 합니다.

int main()
{
	// B의 생성자는 trivial 할까요 ?

	B* p = static_cast<B*>(malloc(sizeof(B)));

	// B 객체를 만들때 생성자 호출이 안되었으므려 
	// 가상함수 테이블 초기화가 안되었씁니다.
	// 아래 코드는 에러 입니다.
	//p->foo(); // runtime error

	new(p) B; // 이미 만들어진 객체의 생성자만 호출
	p->foo();
}