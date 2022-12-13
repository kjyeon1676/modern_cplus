#include <iostream>

// 90 page
void foo(int& a)       { std::cout << "int&" << std::endl; }		// 1
void foo(const int& a) { std::cout << "const int&" << std::endl; }	// 2
void foo(int&& a)      { std::cout << "int&&" << std::endl; }		// 3

int main()
{
	int n = 10;
	foo(n);		// 1�� ȣ��, ������ 2�� ȣ��
	foo(10);	// 3�� ȣ��, ������ 2�� ȣ��

	int& r1 = n;
	foo(r1);	// 1�� ȣ��, ������ 2��. 


	int&& r2 = 10;	// �� ���ٿ��� "10" �� rvalue
					// r2�� lvalue �Դϴ�.
					// 
	// ����Ÿ Ÿ�԰� value �Ӽ��� �򰥸��� ������
	//			Ÿ��			value �Ӽ�
	// n		int			lvalue
	// 10		int			rvalue
	// r1		int&		lvalue
	// r2		int&&		lvalue

	// foo(int&)  : �Լ����ڷ� lvalue �� �ްڴٴ��ǹ�
	// foo(int&&) : �Լ����ڷ� rvalue �� �ްڴٴ��ǹ�
	//			    �Լ� ���ڷ� "int&&" Ÿ���� �ްڴٴ� ���� �ƴմϴ�.

	foo(r2);					// foo(int&)  r2�� lvalue  �̹Ƿ�
	foo(static_cast<int&&>(r2));// foo(int&&) r2�� rvalue �� ĳ����
		//=> �̹� r2�� Ÿ���� int&& �ε�, �ٽ� int&& �� ĳ�����ϴ� ����
		//   �ƹ� �ǹ� ���� �ʳ��� ?
		//=> �� �ڵ�� "Ÿ�� ĳ����"�� �ƴ� "value �� �Ӽ��� �����ϴ� ĳ����"
		//   �̶�� ���� �Ǿ� �ֽ��ϴ�.
		//   lvalue => rvalue �� �����Ҷ� ����մϴ�.
	

}







