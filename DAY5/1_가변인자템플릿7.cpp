// 7_�����������ø�7
#include <iostream>

void foo(int a, int b, int& c) { c = 100; }

// �������� ���ø��� 
// => ����ϴ� �������� ��Ÿ���� �ֽ��ϴ�.
// => �Ʒ� �ڵ�� �Լ��� �Լ��� ���� ���� �Ѱ��� �޾Ƽ� �����մϴ�.
/*
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& args)
{
	return f( std::forward<T>(arg)); 
}
*/

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f( std::forward<Types>(arg)... );
		// f( std::forward<Types>(E1), 
		//    std::forward<Types>(E2)
		//    std::forward<Types>(E3))
}

int main()
{
	int n = 10;
	chronometry(foo, 1, 2, n);

	std::cout << n << std::endl;
}

