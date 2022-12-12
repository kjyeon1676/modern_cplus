#include <iostream>

class Base
{
public:
	virtual void foo(int* const arg) 
	{
		std::cout << "Base foo" << std::endl;
	}
};

class Derived : public Base
{
public:
	virtual void foo(int* arg) override 
	{
		std::cout << "Derived foo" << std::endl;
	}
};

int main()
{
	Base* p = new Derived;
	p->foo(0);
}