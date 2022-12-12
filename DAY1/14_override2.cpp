#include <iostream>

template<typename T> 
class Base
{
public:
	// "arg" 가 const 입니다.
	virtual void foo(const T arg)
	{
		std::cout << "Base foo" << std::endl;
	}
};
class Derived : public Base<int*>
{
public:
	// "arg" 가 const 가 아니라, "arg"를 따라가면 const 가 있다는것
	//virtual void foo(const int* arg) override 

	// 아래 코드가 "arg" 가 const 인 코드 입니다.
	virtual void foo(int* const arg) override
	{
		std::cout << "Derived foo" << std::endl;
	}
};


int main()
{
	Base<int*>* p = new Derived;
	p->foo(0); // "Derived foo" 나와야 합니다.
}