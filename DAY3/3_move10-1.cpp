#include <iostream>
#include <vector>
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
	Object(Object&& obj) 
		: id(obj.id), 
		  name(std::move(obj.name)), 
		  data(std::move(obj.data))
	{
		std::cout << "move" << std::endl;
	}
};
int main()
{

}

