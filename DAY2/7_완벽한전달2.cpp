// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a) {}
void goo(int& a) { a = 100; }

// �Ϻ��� ������ �Ϸ���
// 1. ���纻�� ����� �Ѵ�.
// 2. const �Ӽ��� �߰��Ǿ �ȵȴ�.

// �ذ�å : int&, int&& ������ ���� �����ؾ� �Ѵ�!

// ==> �Ʒ� �ڵ�� �Ѱ��� �������� �ֽ��ϴ�. "�Ϻ�������3.cpp" ����

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
	int n = 10;

	chronometry(foo, 10); 
	chronometry(goo, n); 

	std::cout << n << std::endl;
}
