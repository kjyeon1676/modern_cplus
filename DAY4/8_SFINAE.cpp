// 5_SFINAE - 
#include <iostream>

// �ٽ� : �Ʒ�ó�� 3���� �Լ��� ������
//        �Լ� ã�� ���� �˾Ƶμ���!!

//template<typename T> 
//void foo(T a)   { std::cout << "T" << std::endl; }

//void foo(int a) { std::cout << "int" << std::endl; }

void foo(...)   { std::cout << "..." << std::endl; }

int main()
{
	foo(3); // 1. int ȣ��. - exactly matching 
			// 2. T ��� - template �� ����ϸ� foo(int)�� 
			//			�����Ҽ� �����Ƿ�
			// 3. ... ���
}