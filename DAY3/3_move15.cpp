// 3_move15 - 10번 복사
#include <iostream>
#include <vector>
#include <type_traits>
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
std::remove_reference_t<T>&&  xmove(T&& obj)
{
	// 인자로 T&& 를 사용할때 아래 캐스팅은 절대 rvalue 캐스팅이 아닙니다.
	// 인자로 lvalue 를 보내면 static_cast<Object&>(obj)
	// 인자로 rvalue 를 보내면 static_cast<Object&&>(obj)
	// 즉, 상황에 따라 다른 캐스팅입니다.
	// static_cast<T&&>(obj);

	// move 의 목표는 무조건 rvalue 로 캐스팅해야 합니다.
	return static_cast< std::remove_reference_t<T> &&>(obj);
}

int main()
{
	Object o1;
	Object o2 = o1;			// copy
	Object o3 = xmove(o1);	// move

	Object o4 = xmove(Object()); // move

}

