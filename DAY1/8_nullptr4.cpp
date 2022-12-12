#include <iostream>

void foo(int* p) {}
void goo(char* p) {}

// nullptr �� ���� ����� ���ô�.
struct xnullptr_t
{
	// �Ʒ� ���� �Լ��� "��ȯ ������" �Լ� �Դϴ�.
	// operator int* () { return 0; }
	// operator char* () { return 0; }

	template<typename T>
	operator T*() { return 0; }
};
xnullptr_t xnullptr;

int main()
{
	foo(xnullptr);	// xnullptr => int* ���� �Ͻ��� ����ȯ �ʿ�
					// => xnullptr.operator int*()
	goo(xnullptr);
}
// nullptr �� ����
// 1. C++11 �� ������ ���� boost ��� ���̺귯������ �� ó�� ����
//    �����߽��ϴ�.
// 2. C++11 ���� ǥ�ؿ� �߰��Ǿ���, ������ nullptr �� ��ü�� �ƴ�
//   Ű���� �Դϴ�.