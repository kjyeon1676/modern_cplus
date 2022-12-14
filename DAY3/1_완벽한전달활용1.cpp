// 8_�Ϻ�������Ȱ��
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector�� ��� �ֱ�. 
	// 1. ��ü�� �����Ŀ� �ֱ�
	// Point pt(1, 2);
	// v.push_back(pt);

	// 2. �ӽð�ü�� �ֱ�
	//v.push_back(Point(1, 2));

	// 3. �ٽ�.
	// => ��ü�� �����Ŀ� �������� ����
	// => ��ü�� ����� ���� ������ ���ڸ� ����
	v.emplace_back(1, 2);
			// => 1,2 �� �޾Ƽ� ���������� new Point(1,2)�� ����
			// => emplace_back �� �ᱹ ���޹��� ���ڰ��� ���
			//    Point �����ڿ� �ٽ� �����ؾ� �մϴ�
			//    �Ϻ��� ���� ����� ����ؾ� �մϴ�.

	std::cout << "-----" << std::endl;
}

// 1, 2 ====> emplace_back  =========> Point ������

