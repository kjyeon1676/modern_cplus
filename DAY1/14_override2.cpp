#include <iostream>

template<typename T> 
class Base
{
public:
	// "arg" �� const �Դϴ�.
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// "arg" �� const �� �ƴ϶�, "arg"�� ���󰡸� const �� �ִٴ°�
	//virtual void foo(const int* arg) override 

	// �Ʒ� �ڵ尡 "arg" �� const �� �ڵ� �Դϴ�.
	virtual void foo(int* const arg) override
	{
		std::cout << "Derived foo" << std::endl;
	}
};


int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" ���;� �մϴ�.
}