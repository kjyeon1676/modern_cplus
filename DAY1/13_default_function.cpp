// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// �ƹ��ϵ� ���� ���� ���ڰ� ���� �����ڸ� ����� 2���� ���
	// Point() {}	// 1. ���� ����ڰ� ����� ���
					//    �����Ϸ��� ������ ������ �˼� �����ϴ�.

	Point() = default;	// 2. �����Ϸ����� ����� �޶�� ��û
						//    �����Ϸ��� ������ ������ ��Ȯ�� �˰� �˴ϴ�.
						//	  ����ȭ�� �ߵ˴ϴ�.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}



