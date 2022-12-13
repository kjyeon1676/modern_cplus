#include <iostream>

// 85 page
struct Base
{
	int value = 10; 
};

struct Derived : public Base
{
	int value = 20;
};

int main()
{
	Derived d;

	std::cout << d.value << std::endl; // 20

	// ��� Ŭ�������� �������� value �����ϴ� ���.
	std::cout << static_cast<Base&>(d).value << std::endl; // 10
	std::cout << static_cast<Base>(d).value << std::endl;  // 10
				// => �� ĳ������ �ӽð�ü�� ����� ǥ����Դϴ�.

	static_cast<Base&>(d).value = 30; // ok
	static_cast<Base>(d).value = 30;  // error.
}
// �ӽð�ü��
// 1. ����ڰ� �ǵ������� ����⵵ �ϰ�
//    => �Լ� ���ڷ� �����ϱ� ����
//    => drawLine(Point(0,0), Point(10,10))

// 2. ��ü�� ��Ÿ������ ��ȯ�ϰų�
//    �� Ÿ�� ĳ������ �ӽð�ü�� �����ϰ� �˴ϴ�.
//    => �׻� ���� �ӽð�ü�� �����Ǵ��� ��Ȯ�� �˰� �־�� �մϴ�.
