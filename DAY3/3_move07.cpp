#include <iostream>
#include <string>

// move 계열 함수에서는 모든 멤버를 move로 옮겨라!!
// => 단, primitive type 이나, 포인터 형 멤버의 경우는 std::move 를
//    사용해도 되지만, 효과는 없습니다.
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
		std::cout << "복사" << std::endl;
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
//		: age(c.age), name(c.name), address(c.address) // 잘못된 코드!
										// => address 의 복사 생성자가 호출되는코드
		: age(c.age), name(c.name), address(std::move(c.address)) // ok!!!
										// => address 의 move 생성자를 호출
	{
		c.name = nullptr;
		std::cout << "이동" << std::endl;
	}


	Cat& operator=(Cat&& c)
	{
		if (this == &c) return *this;

		age = c.age;
//		address = c.address; // 이렇게 하면 안됩니다. string 복사 생성자!!
		address = std::move(c.address); // 이렇게 해야 합니다.

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




