// 8_nullptr2
#include <iostream>

void foo(int* p)
{
}

template<typename T>
void forward_foo(T arg)
{
	foo(arg);
}

int main()
{
	foo(0); //ok
	forward_foo(0); // error 왜 에러인지 생각해 보세요
}







