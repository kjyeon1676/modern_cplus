#include <iostream>

template<typename T> 
class Base
{
public:
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// override 붙이지 말고, foo 를 재정의 해서 "Derived foo" 출력하세요
};
int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나와야 합니다.
}