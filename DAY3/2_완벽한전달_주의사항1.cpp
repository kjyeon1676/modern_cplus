// 9_�Ϻ�������_���ǻ���
#include <iostream>

// �Ϻ��� ������ ����ϴ� ��� ������
// => chronometry, 
// => emplace_back
// => make_shared ���� ����Ҷ��� ������ �ǹ��� 0�� ������� ������
// => �ݵ�� nullptr �� ����ϼ���..



template<typename F, typename T>
void chronometry(F f, T&& arg)	// int&& arg = 0
{								// foo(arg) �� ����!
	f(std::forward<T>(arg));
}

void foo(int* p) {}

int main()
{
	foo(0); // ok
	chronometry(foo, 0); // error
	chronometry(foo, nullptr); // error

}









