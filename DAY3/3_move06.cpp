#include <iostream>

// rule of 3 ( C++98 ����)
// => Ŭ�����ȿ� �����Ͱ� �ְ�, ���� �޸� �Ҵ���� ����ϸ�
// => 3���� ��� �Լ��� �ݵ�� ������ �մϴ�.
// => �Ҹ���, ���� ������, ���Կ�����

// rule of 5 ( C++11 ����)
// => rule of 3 ���ٰ� 2���� �� ������ ��
// => move ������, move ���Կ����� 

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* n, int a) : age(a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	~Cat() { delete[] name; }

	Cat(const Cat& c) : age(c.age)
	{
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);
		std::cout << "����" << std::endl;
	}
	// ���Կ�����
	Cat& operator=(const Cat& c)
	{
		if (this == &c) return *this;

		age = c.age;

		delete[] name; // �ڽ��� ����ϴ� �ڿ��� �����ϰ�
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}


	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "�̵�" << std::endl;
	}

	Cat& operator=(Cat&& c)
	{
		if (this == &c) return *this;
		
		age = c.age;

		delete[] name; // �ڽ��� ����ϴ� �ڿ��� �����ϰ�
		
		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// ���� ������
	c2 = c1;		// ���� ������ ( c2.operator=(c1)) 

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




