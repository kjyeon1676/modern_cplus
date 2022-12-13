#include <iostream>

// 85 page
struct Base
{
	int value = 10; 
};

struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20

	// 기반 클래스에서 물려받은 value 접근하는 방법.
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
				// => 값 캐스팅은 임시객체를 만드는 표기법입니다.

	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30;  // error.
}
// 임시객체는
// 1. 사용자가 의도적으로 만들기도 하고
//    => 함수 인자로 전달하기 위해
//    => drawLine(Point(0,0), Point(10,10))

// 2. 객체를 값타입으로 반환하거나
//    값 타입 캐스팅은 임시객체를 생성하게 됩니다.
//    => 항상 언제 임시객체가 생성되는지 정확히 알고 있어야 합니다.
