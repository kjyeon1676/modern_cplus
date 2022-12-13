// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// �ӽð�ü�� �Լ� ��ȯ�� -  82 page
/*
void f1(Point  pt) {} // call by value     : ���纻 ��ü ����
void f2(Point& pt) {} // call by reference : ���纻 ��ü ���� �ȵ�

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//============================================


Point pt(1, 2);

Point foo()		// return by value
{
	return pt;	// pt�� �����ؼ� ���Ͽ� �ӽð�ü ������
				// �ӽð�ü ��ȯ
}
Point& goo()	// return by reference
{		
	return pt;	// pt�� ���纻�� ������ ����..
}				// pt��ü�� ��ȯ�� �޶�.!

int main()
{
//	foo().x = 10;	// error. "�ӽð�ü.x = 10" �� �ǹ�.
	goo().x = 10;   // ok...  "pt.x = 10"
}

Point& hoo()
{
	Point p(1, 2);
	return p;	// ����!!
				// ���� ���������� ���� ��ȯ�ϸ� �ȵ˴ϴ�.
				// �� ��ȯ�� ����ؾ� �մϴ�.
}






