// 3_�ӽð�ü1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// �ӽð�ü�� �Լ� ���� - 81 page
void foo(const Point& pt) {}

int main()
{
//	Point pt(1, 2);	// pt�� foo �� �����ϱ� ���ؼ��� ������ٸ�
//	foo(pt);		// ������ �ڿ��� ���̻� pt�� �ʿ� ����.
					// ������ pt �� �̸��� �����Ƿ� ��� �ı��ɼ�����
					// {}�� ����� �ı� �ȴ�.

	// �ٽ� 1: �Լ� ���ڷθ� ���� ��ü��� �ӽð�ü(�̸����� ��ü)��
	// ����ϴ� ���� ȿ�����Դϴ�.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}

// �ٽ� 2. �Լ� ���ڿ� ���۷���
// �Լ� ���ڷ� "non-const reference" �� ����ϴ� ���
// => ���޵� ��ü�� �����ϰڴٴ°�
// => �ӽð�ü�� �����Ҽ� ����.!!
void init(Point& pt) { pt.x = 0; pt.y = 0; }

init(Point(1, 2)); // error �� ���;� �ϰ�, error �Դϴ�.


// �Լ� ���ڷ� "const reference" �� ����ϴ� ���
// => ���޵� ��ü�� �б⸸ �ϰڴٴ� �ǵ�
// => �ӽð�ü�� �����Ҽ� �־�� �Ѵ�.
void drawLine(const Point& from, const Point& to) {} 

drawLine( Point(0, 0), Point(100, 100) ); // ok


// C++11 ������ �ӽð�ü�� �Լ� �� �����ϴµ�..
// "�ӽð�ü�� ���� �ؾ� �ϴ� ��찡 ������ϴ�." => move.. �ð���.. 




