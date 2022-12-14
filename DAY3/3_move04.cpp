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
	
	// 임시객체(rvalue)를 위한 복사 생성자를 별도로 제공합니다.	
	Cat(Cat&& c) : name(c.name), age(c.age)
	{
		// 임시객체가 사용하던 자원을 빼앗고..
		// name = c.name;

		// 임시객체가 자원 포인터는 0 으로 reset
		// 이 작업을 하려면 임시객체를 상수성 없이 받을수 있어야 합니다.
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