// new1
#include <iostream>

struct Point
{
	int x, y;

	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point(int, int)" << std::endl; }
};

int main()
{
	// ���� ��ü�� �Ѱ� ����� �ʹ�!!!
	Point* p1 = new Point(0, 0);

	// ���� ��ü�� 10�� ����� ������
//	Point* p2 = new Point[10]; // ����Ʈ �����ڰ� �־�� �մϴ�.
								// error.

	// ������ ȣ��� �޸� �Ҵ��� �и��ϸ� �׻� �������� �����ϴ�.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// �̹� �Ҵ�� �޸𸮿� 10���� ��ü�� �����մϴ�.
	for (int i = 0; i < 10; i++)
	{
	//	new(&p2[i]) Point; // ����Ʈ ������
		new(&p2[i]) Point(0,0); // ���� 2�� ������
	}

	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	operator delete(p2);

}	



