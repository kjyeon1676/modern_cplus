#include <iostream>

// rule of 3 ( C++98 시절)
// => 클래스안에 포인터가 있고, 동적 메모리 할당등을 사용하면
// => 3개의 멤버 함수를 반드시 만들어야 합니다.
// => 소멸자, 복사 생성자, 대입연산자

// rule of 5 ( C++11 시절)
// => rule of 3 에다가 2개를 더 만들라는 것
// => move 생성자, move 대입연산자 

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
		std::cout << "복사" << std::endl;
	}
	// 대입연산자
	Cat& operator=(const Cat& c)
	{
		if (this == &c) return *this;

		age = c.age;

		delete[] name; // 자신이 사용하던 자원을 제거하고
		name = new char[strlen(c.name) + 1];
		strcpy_s(name, strlen(c.name) + 1, c.name);

		return *this;
	}


	
	Cat(Cat&& c): age(c.age), name(c.name)
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}

	Cat& operator=(Cat&& c)
	{
		if (this == &c) return *this;
		
		age = c.age;

		delete[] name; // 자신이 사용하던 자원을 제거하고
		
		name = c.name;
		c.name = nullptr;

		return *this;
	}
};

int main()
{
	Cat c1("nabi", 2);

	Cat c2 = c1;	// 복사 생성자
	c2 = c1;		// 대입 연산자 ( c2.operator=(c1)) 

	Cat c3 = std::move(c1);
	c3 = std::move(c2);

}




