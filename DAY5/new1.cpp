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
	// new 의 동작 방식
	// 1. 메모리 할당 - operator new()
	// 2. 생성자 호출 - 
//	Point* p1 = new Point(1, 2);

	// delete 동작 방식
	// 1. 소멸자 호출
	// 2. 메모리 해지 - operator delete();
//	delete p1;

	// 1. 메모리만 할당
	Point* p2 = static_cast<Point*>( operator new(sizeof(Point)) );

	// 2. 메모리 할당없이 생성자만 호출
	new (p2) Point(1, 2);

	// 3. 메모리 해지 없이 소멸자만 호출
	p2->~Point();

	// 4. 메모리만 해지
	operator delete(p2);
}