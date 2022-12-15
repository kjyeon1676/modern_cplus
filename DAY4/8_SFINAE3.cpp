#include <iostream>

int foo(...) { std::cout << "..." << std::endl; return 0; }

// �Ʒ� �ڵ�� SFINAE �� ����ɱ�� ?
// => ������� �ʽ��ϴ�
// => error �Դϴ�.
/*
template<typename T>
int foo(T arg)
{
	typedef T::type n; // ?
	 
	return 0;
}
*/
// SFINAE �� �Լ� signature �� ���� �Ҷ��� ����˴ϴ�.

// 1. ���� Ÿ�� - ���� �θ� ���
// template<typename T>
//typename T::type foo(T arg) { return  0; }

// 2. �Լ� ���� Ÿ��
//template<typename T>
//int foo(T arg, typename T::type arg2 = 0 ) { return  0; }


// 3. ���ø� ���� Ÿ�� 
// => �����ڴ� ��ȯ Ÿ���� ���µ�..
// => �����ڿ��� "SFINAE" ����� ����Ҷ� �θ� ���

template<typename T, typename T2 = typename T::type>
int foo(T arg ) { return  0; }

int main()
{
	foo(3);
}