// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체의 특징 - 79 page
int main()
{
	Point pt(1, 2);
	
	// 특징 1. 
	pt.x = 10;			// ok.
	Point(1, 2).x = 10;	// error. 임시객체는 등호의 왼쪽에 올수 없습니다.
						// 임시객체는 lvalue 가 될수 없습니다.(rvalue입니다.)

//	Point(1, 2).set(10, 20); // ok.  임시객체는 상수인것은 아닙니다.
							 // 멤버 함수로 상태 변경은 가능합니다.
							 // 단지, 문법상 등호의 왼쪽에 올수 없습니다.

	// 특징 2.
	Point* p1 = &pt;			// ok	
	Point* p2 = &Point(1, 2);	// error. 임시객체는 주소연산자로
								//		  주소를 구할수 없습니다.
							

	// 특징 3. 
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. 임시객체는 참조로 가리킬수		
								//        없습니다.
}





