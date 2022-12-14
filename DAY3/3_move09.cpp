#include <iostream>
#include <string>

// rule of 0 
// => 자원 관리를 직접 하지 말고
// => 표준 라이브리러를 사용해라
// => 복사와 move를 모두 만들지 않으면 컴파일러가 모두 제공한다!!
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




