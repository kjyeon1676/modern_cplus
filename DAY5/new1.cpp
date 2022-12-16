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

// malloc : 메모리의 할당 입니다.
// new    : 객체의 생성 입니다.( 메모리 할당 + 생성자 호출(초기화))

// new    Point(0,0) : 새로운 메모리를 할당하고 객체를 생성해 달라.
// new(p) Point(0,0) : 이미 존재하는 메모리주소(p)에 객체를 생성해 달라
//						=> placement new 라고 합니다.