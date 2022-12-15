#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3 �� �ֽ��ϴ�.

//	goo(args); // error. pack �� ���ڷ� ���� ����Ҽ� �����ϴ�.



	// �ٽ� 1. Pack Expansion
	// "��������ϴ� ����" ...  => "E1����", "E2����", "E3����"

	goo(args...); // ok.. pack �� ��� ��Ҹ� , �� ����ؼ� �����ش޶�
				  // goo(1, 2, 3);

	goo((++args)...);	// goo(++E1, ++E2, ++E3 )
						// goo(++args...) ó�� () ��� �˴ϴ�.
}


int main()
{
	foo(1, 2, 3);
}
