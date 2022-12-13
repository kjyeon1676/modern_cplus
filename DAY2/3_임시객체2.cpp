// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� Ư¡ - 79 page
int main()
{
	Point pt(1, 2);
	
	// Ư¡ 1. 
	pt.x = 10;			// ok.
	Point(1, 2).x = 10;	// error. �ӽð�ü�� ��ȣ�� ���ʿ� �ü� �����ϴ�.
						// �ӽð�ü�� lvalue �� �ɼ� �����ϴ�.(rvalue�Դϴ�.)

//	Point(1, 2).set(10, 20); // ok.  �ӽð�ü�� ����ΰ��� �ƴմϴ�.
							 // ��� �Լ��� ���� ������ �����մϴ�.
							 // ����, ������ ��ȣ�� ���ʿ� �ü� �����ϴ�.

	// Ư¡ 2.
	Point* p1 = &pt;			// ok	
	Point* p2 = &Point(1, 2);	// error. �ӽð�ü�� �ּҿ����ڷ�
								//		  �ּҸ� ���Ҽ� �����ϴ�.
							

	// Ư¡ 3. 
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. �ӽð�ü�� ������ ����ų��		
								//        �����ϴ�.
}





