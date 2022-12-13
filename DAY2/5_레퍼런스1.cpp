// 3_���۷���1.cpp - 89 page - ���� �߿�!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// ��Ģ 1. non-const lvalue reference �� lvalue �� ����ų�� �ִ�.
	Point& r1 = pt;			// ok
	Point& r2 = Point(0, 0);// error


	// ��Ģ 2. const lvalue reference �� lvalue �� rvalue�� ��� ����ų�� �ִ�.
	const Point& r3 = pt;		  // ok
	const Point& r4 = Point(0, 0);// ok.


	// ��Ģ 3. C++11�� ���ο� rvalue reference
	// => C++11 ���鶧 �ӽð�ü(rvalue)�� ��������� ����Ű��
	//    �;���.(move�� �Ϻ��� ������ ���� )
	// => non-const rvalue reference �� rvalue �� ����Ų��.
	Point&& r3 = pt;			// error
	Point&& r4 = Point(0, 0);	// ok


	// const rvalue reference �� rvalue �� ����ŵ�ϴ�.
	// => �׷���, ������ �ʱ� ������ ���� ������ ��������� �ʽ��ϴ�.
	// const Point&& r3 = pt;			// error
	// const Point&& r4 = Point(0, 0);	// ok
}