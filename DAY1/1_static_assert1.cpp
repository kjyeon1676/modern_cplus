#include <cassert>

// assert : ����ð��� ǥ������ ��ȿ���� ����
// static_assert : ������ �ð� assert - C++11
//				   ������ �ð��� ��ȿ�� ����
//				   Ű����. include �ʿ� ����

static_assert(sizeof(int*) >= 8, "error, not 64bit");

void foo(int age)
{
	// �Լ� ���ڸ� �ٷ� ������� ����.. 
	// ���ڰ��� ��ȿ���� Ȯ���ϴ� ���� �����մϴ�.
	assert( age > 0 );

	// age > 0 �̶�� �����ϰ� �������� �ڵ� �ۼ�
	int* p = new int[age];

	delete[] p;
}

int main()
{
	foo(10);
	//foo(-10);
}