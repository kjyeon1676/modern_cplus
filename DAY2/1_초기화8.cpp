// 1_�ʱ�ȭ8 - 62page
#include <iostream>
#include <initializer_list> // �ٽ�

// list	  : ������ �޸�, ��� ��� ��
// vector : ���ӵ� �޸�, ��� ��� ��
// initializer_list : ���ӵ� �޸�, ��� ��Ұ� ����,
//					  �����ּҿ� ����(�Ǵ� ������ �ּ�)�� ����
//				      �ʱ�ȭ�� ���� Ư���� ���ǵ� ������ �����.

void foo(std::initializer_list<int> e)
{
}
int main()
{
	// C++11 ���� �ʱ�ȭ�� �������� ���� Ÿ��
	// => ���������� "������ 2��(vc)" �Ǵ� "������ �Ѱ�+����(g++)"�� ����
	// => ����Ÿ ��ü�� �Ʒ� ó�� �Լ� �ȿ� ������ stack ��..

	std::initializer_list<int> e = { 1,2,3,4,5 };

	auto p1 = e.begin();
	auto p2 = e.end();

	foo(e);
	foo({ 1,2,3,4,5 });
	foo({ 1,2,3,4,5,6,7,8,9,10 });
}

