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

	// move �����ڿ����� ��� ����� std::move �� �Űܶ�
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

