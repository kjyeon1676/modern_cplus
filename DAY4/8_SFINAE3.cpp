#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

// �Ʒ� �ڵ�� SFINAE �� ����ɱ�� ?
template<typename T>
int foo(T arg)
{
	typedef T::type n; // ?
	 
	return 0;
}

int main()
{
	foo(3);
}