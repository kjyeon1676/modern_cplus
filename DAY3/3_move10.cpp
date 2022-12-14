#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) {	std::cout << "copy" << std::endl;	}
	
	// 핵심 : move 계열 함수를 만들때는
	// => 되도록 예외가 발생되지 않게 만드세요
	// => 그리고, 예외가 없음을 알리기 위해 꼭 noexcept 를 붙이세요

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{
	Object o1;
	Object o2 = o1; // 항상 복사 생성자 사용
	Object o3 = std::move(o1); // 항상 move 생성자 사용
	Object o4 = std::move_if_noexcept(o2); // 핵심
						// => move 생성자에 예외가 없으면 move 생성자사용
						// => move 생성자에 예외 가능성이 있으면 copy 사용


	std::vector<Object> v(3);

	std::cout << "----------------" << std::endl;

	v.resize(5); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

