#include <iostream>

// �Լ���ü�� const member function

struct Plus
{
	// �ٽ� : �Լ� ��ü ���鋚, () ������ �Լ��� ����
	//       ��� ��� �Լ��� �ϴ� ���� ��Ģ �Դϴ�.
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};

template<typename T> void foo(const T& f)
{
	// ��� ��ü�� ��� ��� �Լ��� ȣ�� �����մϴ�.
	// ���� f�� ��� ��ü �̹Ƿ� 
	// �Ʒ� ó�� ��밡���Ϸ���, "operator()" �������Լ���
	// �ݵ�� ��� ��� �Լ����ؾ� �մϴ�.

	int ret = f(1, 2); // f.operator()(1,2)
}

int main()
{
	Plus p;

	foo(p);
}
