#include <iostream>
// ��Ģ 1. ���ø� �Ķ���Ͱ� "��(T a)" Ÿ�� �϶�
// => �Լ� ���ڰ� ���� "const, volatilie, reference" �Ӽ��� ����
//    �ϰ� T�� Ÿ���� �����Ѵ�.
template<typename T> void foo(T a)
{
	// Ȯ���ϴ� ��� 1. C++ ǥ�� rtti ��� ���
	std::cout << typeid(T).name() << std::endl;

	a = 100;
}

int main()
{
	// ����ڰ� Ÿ������
	// => �����Ϸ��� Ÿ���� �߷��� �ʿ� ����. ������ ����ڰ� ������ Ÿ�Ի��
	foo<int>(3);

	// Ÿ���� �������� ������ �Լ� ���ڸ� ���� Ÿ���� �߷��մϴ�.
	foo(10); // T=int
	foo(3.4);// T=double


	int n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;
	
	foo(n);		// T=int
	foo(c);		// T=int
	foo(r);		// T=int
	foo(cr);	// T=int
}