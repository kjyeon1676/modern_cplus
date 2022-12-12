//8_nullptr3
#include <iostream>

void foo(int)    { std::cout << "int" << std::endl; }
void foo(double) { std::cout << "double" << std::endl; }
void foo(bool)   { std::cout << "bool" << std::endl; }
void foo(char*)  { std::cout << "char*" << std::endl; }

int main()
{
	foo(0);		// int,  0�� ������ ���ͷ�
	foo(0.0);	// double, 0.0 �� �Ǽ��� ���ͷ�
	foo(false);	// bool
	foo(nullptr); // nullptr �� �������� "���ͷ��Դϴ�."
				  // C++���� ������ �ƴ� ���ͷ��� �����մϴ�.

	// nullptr �� ����Ÿ Ÿ���� std::nullptr_t ��� Ÿ���Դϴ�.
	std::nullptr_t arg = nullptr;

	// std::nullptr_t Ÿ���� ��� ������ �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
	int* p1 = arg;
	char* p2 = arg;
}



