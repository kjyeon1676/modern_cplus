#include <iostream>

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

	Cat(Cat&& c) : name(c.name), age(c.age)
	{
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
	Cat c1("nabi", 2);
	Cat c2 = c1;	// copy
	Cat c3 = foo();	// move

	// c1은 lvalue 지만 의도적으로 rvalue로 캐스팅하면 
	// => move 생성자가 호출됩니다.
	Cat c4 = static_cast<Cat&&>(c1);

	Cat c5 = std::move(c2); // std::move 표준함수가 하는일이
			// 위와 같이 rvalue 로 캐스팅하는 작업을 하게 됩니다.

	// 핵심 1. std::move() 가 자원을 이동하는 것이 아닙니다.
	//         => 객체를 rvalue 로 캐스팅을 할뿐입니다.
	//		   => 캐스팅의 결과로 move 생성자가 호출되었고
	//		   => move 생성자안에서 자원의 move 가 되는 원리 입니다

	// 핵심 2. move 생성자를 만들지 않았는데.. std::move를 사용했다면

	Cat c6 = std::move(c3); // static_cast<Cat&&>(c3)
	
	// 1. move 생성자가 있다면 move 생성자를 사용합니다.
	// 2. move 생성자가 없다면 복사 생성자를 사용하게 됩니다.

	// 즉, move 생성자를 만들지 않은 타입도 std::move() 사용해도 됩니다.
	// => 단, 성능의 향상은 없고,, 복사 생성자를 사용하게 됩니다.
}