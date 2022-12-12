// 3_noexcept - 14 page
#include <iostream>
#include <exception>

// noexcept Ű������ 2���� �뵵
// 1. �Լ��� ���ܰ� �ִ��� ����
// 2. �Լ��� ���ܰ� ������ �˸��� ���

void foo()	// ���ܰ� �߻��� ���ɼ��� ����.
{
}
void goo() noexcept  // ���� �߻����ɼ��� ������ �����Ϸ����� �˸���
{	
}

int main()
{
	// �Լ��� ���ܰ� �ִ��� �����ϴ� ���
	// => noexcept(�Լ�ȣ���)
	// => ������ �Լ��� ȣ���ϴ� ���� �ƴϰ�,
	// => �Լ��� ȣ�������� ������ ���ɼ��� �ִ����� ����
	// => �ᱹ, �Լ� ����ڿ� noexcept �� �ִ��� �����ϴ� ��!
	bool b1 = noexcept(foo());	// false
	bool b2 = noexcept(goo());  // true
}




