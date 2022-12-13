#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

void hoo(int&& arg) {}

/*
template<typename F>
void chronometry(F f, int& arg)
{
//	f(arg);
	f( static_cast<int&>(arg) ); // �ʿ���� ĳ����������
								 // �־ ���� ������ ���� �ʽ��ϴ�.
}
template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}
*/

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(static_cast<T&&>(arg));
}

int main()
{
	int n = 0;
	chronometry(foo, 10);
	chronometry(goo, n);
}
