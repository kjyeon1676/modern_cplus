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
	// 힙에 객체를 한개 만들고 싶다!!!
	Point* p1 = new Point(0, 0);

	// 힙에 객체를 10개 만들어 보세요
//	Point* p2 = new Point[10]; // 디폴트 생성자가 있어야 합니다.
								// error.

	// 생성자 호출과 메모리 할당을 분리하면 항상 유연성이 좋습니다.
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 이미 할당된 메모리에 10개의 객체를 생성합니다.
	for (int i = 0; i < 10; i++)
	{
	//	new(&p2[i]) Point; // 디폴트 생성자
		new(&p2[i]) Point(0,0); // 인자 2개 생성자
	}

	for (int i = 0; i < 10; i++)
		p2[i].~Point();

	operator delete(p2);

}	



