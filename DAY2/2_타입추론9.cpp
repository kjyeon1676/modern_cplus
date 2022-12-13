#include <iostream>

int x = 0;

int& foo(int n, double d) { return x; }

int main()
{
	auto ret = foo(1, 3.4); // auto�� �캯�� ������
//  int  ret = foo(1, 3.4); // �����ϰ� Ÿ�� ����

	// decltype(�Լ�ȣ���) : �Լ� ȣ���� ����� ������ Ÿ��
	//						 �Լ� ������ ���� ����
	//						 "�Լ� ȣ���"�� ���� ����Ǵ� ���� �ƴ�
	decltype( foo(1, 3.4) ) ret2 = foo(1, 3.4);
//	int&	ret2 = foo(1, 3.4);

	// decltype(auto) : C++14 ���� ����
	// => auto �ڸ��� �캯 ǥ������ �־� �޶�.
	// => �Ǵ� �캯���� ǥ�������� Ÿ���� �߷��ϴ� ��, 
	//    ��Ģ�� decltype ��Ģ ���

	decltype(auto) ret3 = foo(1, 3.4);
//	int&	ret3 = foo(1, 3.4);
}