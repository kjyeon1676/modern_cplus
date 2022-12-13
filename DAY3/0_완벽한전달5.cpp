#include <iostream>

void hoo(int&& arg) {}
// ����
// �Ϻ��� ������ �Ϸ���
// 1. int& �� int&& ������ �Լ��� ���� ����
// 2. int&& ������ ���ڸ� rvalue ĳ������ �Ŀ� forwarding

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}


int main()
{
	hoo(10);

	chronometry(hoo, 10);
}
