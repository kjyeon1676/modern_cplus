// 7_�Ϻ�������1 - 113 page
#include <iostream>

void foo(int a)  {}
void goo(int& a) { a = 100; }

// forwarding : ���� ���ڸ� �ٸ� �Լ��� �����ϴ� ��
// 
// perfect forwarding(�Ϻ��� ����)
// => ���� ���ڸ� �ٸ� �Լ��� �����Ҷ� 
//    ��� ��ȯ�� ���� ���� �״�� �����ϴ� ���

// ���ڷ� ���޵� �Լ��� ����(����ð�)�� �����ϴ� �Լ�
template<typename F, typename T>
void chronometry(F f, T arg)
{
	// �ð��� ������ ����
	f(arg);	// �Լ� ȣ��
	// �ٽ� �ð��� ������, �ҿ�ð� ���
}

int main()
{
	int n = 10;

	chronometry(foo, 10); // foo(10);
	chronometry(goo, n);  // goo(n);

	std::cout << n << std::endl;
}
