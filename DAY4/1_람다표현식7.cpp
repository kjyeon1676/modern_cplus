// 145 page
#include <iostream>
int main()
{
	// ����ǥ������ ��Ȯ�� ���
	auto f1 = [](int a, int b) -> int { return a + b; };

	// 1. return ������ �Ѱ���� ���� Ÿ���� ���������մϴ�.
	auto f2 = [](int a, int b) { return a + b; };

	// 2. return ������ ������ �� ���� Ÿ���� ��ȯ�ϸ� ���������մϴ�.
	auto f3 = [](int a, int b) { if (a == 1) return a; return b; };

	// 3. return ������ ������ �ε�, �ٸ� Ÿ���� ��ȯ�ϴ� ���
	//    �ݵ�� ���� Ÿ���� ��������� ǥ���ؾ� �մϴ�.
	//    �Ʒ� �ڵ�� ����
	auto f4 = [](int a, double b) { if (a == 1) return a; return b; }; 

	// �Ʒ� ó�� ǥ���ؾ� �մϴ�.
	auto f4 = [](int a, double b)-> double { if (a == 1) return a; return b; };
}

