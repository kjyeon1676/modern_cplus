#include <iostream>

template<typename T> void printv(const T& a)
{
	std::cout << a << std::endl;
}

template<typename ... Types> void foo(Types ... args)
{
//	printv(args...);	// printv(1, 2, 3) �̹Ƿ� ����

//	printv(args)...; // �ǵ� : printv(1), printv(2), printv(3) 
					 // error.

	// �ٽ� 1. pack expansion �� ������ ��ġ�� ������ �ֽ��ϴ�.
	// 1. �Լ� ȣ���� () ��
	// 2. {} �ʱ�ȭ �� 

	int x[] = { printv(args)... };
			//{ printv(E1), printv(E2), printv(E3) };
}




int main()
{
	foo(1, 2, 3);
}

