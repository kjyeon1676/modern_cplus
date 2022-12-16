#include <iostream>
#include <functional>
using namespace std::placeholders;

void foo(int a, int& b) { b = 100; }

int main()
{	
	std::function<void(int)> f;

	int n = 0;

//	f = std::bind(&foo, _1, n);  // �� ������ ���� �� ���ô�.
								// 1. n �̶�� ������ �����ɱ�� ?
								// 2. n �� ���� �����ɱ�� ?
								// => ���� 2��, n�� ���� �����ϰ� �ִٰ� ���

	f = std::bind(&foo, _1, std::ref(n) ); // n�� ���� �������� ����
								// n ��ü�� ������ ������ �޶�

	f(0); // foo(0, n)

	std::cout << n << std::endl; // ��� ������ ������
}


