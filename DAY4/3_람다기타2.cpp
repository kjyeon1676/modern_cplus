#include <iostream>

// �Լ� ���ڷ� auto ����� "C++20" ���� ���� �մϴ�.
// void foo(auto n) {} 


int main()
{
	// generic lambda
	auto f = [](int a, int b) { return a + b; };

	int    n = f(1, 2);
	double d = f(3.2, 3.2); // ������ �ƴ�����
							// ����� 6
	
	// �ٽ� 1. Generic lambda
	// => C++14 ���� ���� ǥ������ ���ڷ� auto ��밡���մϴ�
	// => �Ϲ��Լ��� C++20 ���� ���ڷ� auto ��밡���մϴ�.
	auto f1 = [](auto a, auto b) { return a + b; };

	std::cout << f1(1, 2) << std::endl;
	std::cout << f1(1.1, 2.1) << std::endl;
	std::cout << f1(1,   2.1) << std::endl;
	std::cout << f1(1.1, 2 ) << std::endl;
}