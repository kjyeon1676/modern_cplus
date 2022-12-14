#include <iostream>
#include <vector>
#include <type_traits>
#include <string>

template<typename T>
class Object
{
	int id;
	std::string name;
	T data;

public:
	Object() {}

	Object(const Object& obj) : id(obj.id), name(obj.name), data(obj.data)
	{ 
		std::cout << "copy" << std::endl; 
	}

	// move 생성자에서는 모든 멤버를 std::move 로 옮겨라
	// void f1() noexcept       : 예외가 없다
	// void f2() noexcept(true) : 예외가 없다
	// void f2() noexcept(false): 예외가 있다

	Object(Object&& obj) noexcept( std::is_nothrow_move_constructible_v<T>)
		: id(obj.id), 
		  name(std::move(obj.name)), 
		  data(std::move(obj.data))
	{
		std::cout << "move" << std::endl;
	}
};

// cppreference.com 에서 std::string 검색


int main()
{

}

