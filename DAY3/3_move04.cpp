#include <iostream>

// shallow copy vs deep copy

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

		std::cout << "copy ctor" << std::endl;
	}
	
	// �ӽð�ü(rvalue)�� ���� ���� �����ڸ� ������ �����մϴ�.	
	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		// �ӽð�ü�� ����ϴ� �ڿ��� ���Ѱ�..
		// name = c.name;

		// �ӽð�ü�� �ڿ� �����ʹ� 0 ���� reset
		// �� �۾��� �Ϸ��� �ӽð�ü�� ����� ���� ������ �־�� �մϴ�.
		c.name = nullptr;

		std::cout << "move ctor" << std::endl;
	}

};

Cat foo()
{
	Cat c("yaong", 2);
	return c;
}

int main()
{
//	Cat c1("nabi", 2);
//	Cat c2 = c1;	// copy  

	Cat c3 = foo();	// move
}