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

	// move �����ڿ����� ��� ����� std::move �� �Űܶ�
	// void f1() noexcept       : ���ܰ� ����
	// void f2() noexcept(true) : ���ܰ� ����
	// void f2() noexcept(false): ���ܰ� �ִ�

	Object(Object&& obj) noexcept( std::is_nothrow_move_constructible_v<T>)
		: id(obj.id), 
		  name(std::move(obj.name)), 
		  data(std::move(obj.data))
	{
		std::cout << "move" << std::endl;
	}
};

// cppreference.com ���� std::string �˻�


int main()
{

}

