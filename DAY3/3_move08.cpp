#include <iostream>
#include <string>

// �ڵ� ���� ��Ģ.

struct Object
{
	std::string name;

	Object(const std::string& n) : name(n) {}
};

int main()
{
	Object o1("obj1");
	Object o2("obj2");

	Object o3 = o1;
	Object o4 = std::move(o2);

	std::cout << o1.name << std::endl; // "obj1"
	std::cout << o2.name << std::endl; // ""
}