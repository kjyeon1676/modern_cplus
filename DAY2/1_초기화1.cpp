// �ʱ�ȭ - 55 page
#include <iostream>

int x = 10;

class Test
{
	// C++11 ���� ��� ����Ÿ�� ���鶧 ���� �ʱⰪ�� �����Ҽ� �ֽ��ϴ�.
	// => ���� �������� ������ �߿��մϴ�.
	int value1 = 0;		// �̷��� 0���� �ʱ�ȭ �ϴ� ���� ������
	int value2 = ++x;	// ����, �̷� �ڵ�� ������� ������..!
public:	
	Test() {}
	Test(int n) : value2(n) {}
};
/*
// �� �ڵ��� ����!!!
// => ��� �ʱⰪ�� �������� �ʱ�ȭ ����Ʈ�� �ű�� �˴ϴ�.
// => �Ʒ� �ڵ� ����
class Test
{
	int value1;// = 0;
	int value2;// = ++x;
public:
	Test()      : value1(0), value2(++x) {}
	Test(int n) : value1(0), value2(n) {}
};
*/
int main()
{
	Test t1;
	Test t2(5);

	std::cout << x << std::endl; // �����غ�����. ? 11
}