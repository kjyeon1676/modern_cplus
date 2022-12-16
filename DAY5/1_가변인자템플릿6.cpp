#include <iostream>

// 233 page �Դϴ�.

// �ٽ� : �Լ��� ��� ���ڸ� �������ڷ� ���� ����
//        1��° ���ڸ� �������� �̸��� ���

void foo() {} // recursive ���� �ڵ��� ���Ḧ ���ؼ�!!

template<typename T, typename ... Types>
void foo(T value, Types ... args)
{
	std::cout << value << std::endl;

	foo(args...); // foo(3.4, 'A')
				  // foo('A');
				  // foo()
}

int main()
{
	foo(1, 3.4, 'A'); 
}





