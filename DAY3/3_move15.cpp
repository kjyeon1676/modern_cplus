// 3_move15 - 10번 복사
#include <iostream>
#include <vector>

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }

	Object(Object&&) noexcept
	{
		std::cout << "move" << std::endl;
	}
};

// std::move 를 만들어 봅시다.
// T& : 인자로 lvalue 만 받겠다는 것 
// T&&: 인자로 lvalue 와 rvalue 를 모두 받겠다는 것

// move 는 lvalue 와 rvalue 를 모두 받을수 있어야 합니다.
template<typename T>
T&& xmove(T&& obj)
{
	return static_cast<T&&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;			// copy
	Object o3 = xmove(o1);	// move

	Object o3 = xmove(Object()); // ??

}

