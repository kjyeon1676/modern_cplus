// 9_�Ϻ�������_���ǻ���
#include <iostream>

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	f(std::forward<T>(arg));
}

void foo() {}
void foo(int a) {}
void foo(int a, int b) {}

int main()
{
	// �Լ��� ���� ȣ���
	// => ���ڸ� ���� ��� �Լ����� ã���� �ִ�.
	foo();
	foo(10);
	foo(10, 20);
 
//	chronometry(foo, 10); // error

	// �����Ϸ��� �������� foo �߿��� � �Լ�������
	// �����Ҽ� �ֵ��� ��Ʈ�� �����ؾ� �մϴ�.(ĳ���� ���� �ڵ�)
	chronometry(static_cast<void(*)(int)>(foo), 10);
}









