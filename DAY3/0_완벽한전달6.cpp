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
	// �Ʒ� ĳ������  chronometry �� 2��° ���ڷ�

	// rvalue �� ������ rvalue �� ĳ�����ϰ� �ǰ�
	// lvluae �� ������ lvalue �� ĳ�����ϰ� �˴ϴ�.
	//f(static_cast<T&&>(arg));

	f( std::forward<T>(arg) );	// �� ĳ���ð� ������ ���� �ϴ�
								// C++ ǥ�� �Լ�
}

int main()
{
	int n = 0;
	chronometry(foo, 10);	// T=int	T&&=int&&	
							// chronometry(F, int&&) ����
							// static_cast<int&&>(arg)

	chronometry(goo, n);	// T=int&		T&&=int&
							// chronometry(F, int&) ����
							// static_cast<int&>(arg)
}
