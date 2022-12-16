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

	// args �� ��� ������ 0�� ��츦 ����ؼ�
	// 1. ���� �տ� ���� 0�� �ְų� 
	//int x[] = { 0, (printv(args), 0)... }; 
			//{ (printv(E1), 0), (printv(E2),0), (printv(E3), 0) };
			// {}

	// 2. 
	std::initializer_list<int> e = { (printv(args), 0)... };
}

int main()
{
//	foo();
	foo(1, 2, 3);
}

