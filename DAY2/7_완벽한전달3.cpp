#include <iostream>

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // error.. ��??? �����ϱ�� ?
						  // => "������ �ذ�å�� 4��" ����
}
