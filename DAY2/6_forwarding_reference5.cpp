#include <iostream>

template<typename T> void foo(T&& arg)
{
	// Ȯ���ϴ¹� => �����Ǵ� �Լ��̸��� ����� ���°��� ����
	// �����ϴ�.
	std::cout << __FUNCSIG__ << std::endl;	
}

int main()
{
	int n = 10;

	foo(n);  //	T=int&   T&&=int&
	foo(10); // T=int    T&&=int&&
}




