#include <iostream>
#include "cppmaster.h"

// ��Ģ 1. ���ø� �Ķ���Ͱ� "��(T a)" Ÿ�� �϶�
// => �Լ� ���ڰ� ���� "const, volatilie, reference" �Ӽ��� ����
//    �ϰ� T�� Ÿ���� �����Ѵ�.
template<typename T> void foo(T a)
{
	// Ȯ���ϴ� ��� 1. C++ ǥ�� rtti ��� ���
	// => �� ����� ������� ������...
	// => C++ǥ���� RTTI ����� const �� reference ���� ��µ��� �ʽ��ϴ�.
	// std::cout << typeid(T).name() << std::endl;

	// Ȯ���ϴ� ��� 2. �Լ� �̸��� ���� ��ũ�� ����ؼ� ���
	// __func__    : C++ ǥ�� ��ũ��, �Լ��� �̸��� ���
	// __FUNCSIG__ : �Լ��̸� + �Լ����� ��� ���, �� VC++ ����
	// __PRETTY_FUNCTION__ : �Լ��̸� + �Լ����� ��� ���, �� g++ ����

	//std::cout << __func__ <<std::endl;

	//std::cout << __FUNCSIG__ << std::endl;

	std::cout << _FNAME_ << std::endl; // cppmaster.h �ִ� ��ũ��
									// vc�� g++ ��� ����.

//	a = 100;
}


int main()
{
	// ����ڰ� Ÿ������
	// => �����Ϸ��� Ÿ���� �߷��� �ʿ� ����. ������ ����ڰ� ������ Ÿ�Ի��
	foo<const int>(3);

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

	// �ٽ� : ���ڰ� ���� const �Ӽ��� ���ŵ˴ϴ�.
	
	const char* name = "hello";

	foo(name); // T = const char* 

	const char* const name2 = "hello";
	foo(name2); //T = const char*
}
