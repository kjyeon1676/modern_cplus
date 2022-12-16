// new1
#include <iostream>

struct Point
{
	int x, y;
	
	Point(int a, int b) : x(a), y(b) {std::cout << "Point(int, int)" << std::endl;	}
	~Point(){ std::cout << "~Point(int, int)" << std::endl; }
};

int main()
{
	// new �� ���� ���
	// 1. �޸� �Ҵ� - operator new()
	// 2. ������ ȣ�� - 
//	Point* p1 = new Point(1, 2);

	// delete ���� ���
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ���� - operator delete();
//	delete p1;

	// 1. �޸𸮸� �Ҵ�
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point)) );

	// 2. �޸� �Ҵ���� �����ڸ� ȣ��
	new (p2) Point(1, 2);

	// 3. �޸� ���� ���� �Ҹ��ڸ� ȣ��
	p2->~Point();

	// 4. �޸𸮸� ����
	operator delete(p2);
}

// malloc : �޸��� �Ҵ� �Դϴ�.
// new    : ��ü�� ���� �Դϴ�.( �޸� �Ҵ� + ������ ȣ��(�ʱ�ȭ))

// new Point(0,0)    : ���ο� �޸𸮸� �Ҵ��ϰ� ��ü�� ������ �޶�.
// new(p) Point(0,0) : �̹� �����ϴ� �޸��ּ�(p)�� ��ü�� ������ �޶�