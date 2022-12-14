#include <iostream>
#include <string>

// rule of 0 
// => �ڿ� ������ ���� ���� ����
// => ǥ�� ���̺긮���� ����ض�
// => ����� move�� ��� ������ ������ �����Ϸ��� ��� �����Ѵ�!!
// char* => string
// int*  => vector, smart pointer

class Cat
{
	std::string name;
	int   age;
	std::string address;
public:
	Cat(const std::string& n, int a, const std::string& addr = "unkwon")
		: name(n),  age(a), address(addr)
	{
	}
};


int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;
	c2 = c1;

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




