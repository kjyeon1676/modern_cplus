#include <iostream>
#include <string>

// move �迭 �Լ������� ��� ����� move�� �Űܶ�!!
// => ��, primitive type �̳�, ������ �� ����� ���� std::move ��
//    ����ص� ������, ȿ���� �����ϴ�.
class Cat
{
	char* name;
	int   age;
	std::string address;
public:
	Cat(const char* n, int a, const std::string& addr="unkwon") 
		: age(a), address(addr)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}


	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age), address(c.address)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}
	


	Cat& operator=(const Cat& c)
	{
		if (this == &c) return *this;

		age = c.age;
		address = c.address;

		delete[] name; 
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}



	Cat(Cat&& c) 
//		: age(c.age), name(c.name), address(c.address) // �߸��� �ڵ�!
										// => address �� ���� �����ڰ� ȣ��Ǵ��ڵ�
		: age(c.age), name(c.name), address(std::move(c.address)) // ok!!!
										// => address �� move �����ڸ� ȣ��
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}


	Cat& operator=(Cat&& c)
	{
		if (this == &c) return *this;

		age = c.age;
//		address = c.address; // �̷��� �ϸ� �ȵ˴ϴ�. string ���� ������!!
		address = std::move(c.address); // �̷��� �ؾ� �մϴ�.

		delete[] name;

		name = c.name;
		c.name = nullptr;

		return *this;
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




