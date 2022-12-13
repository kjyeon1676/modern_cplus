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
								// VS2017의 일부 버전에서 에러가 아닌 경우가 있습니다.
							

	// 특징 3. 
	Point& r1 = pt;				// ok
	Point& r2 = Point(1, 2);	// error. 임시객체는 참조로 가리킬수		
								//        없습니다.

	// 특징 4. 중요!!!
	const Point& r3 = Point(1, 2);	// ok. 임시객체를 상수 참조로는
									// 가리킬수 있다.
						// => 이 경우 임시객체의 수명은 r3의 수명
						//    으로 연장됩니다.
	r3.x = 10;	// error. 단, 상수성이 있는 참조 이므로 
				//		  상태 변경은 안됩니다.

	//============================================
	// 특징 5. C++11 에서는 임시객체를 상수성 없이 가리키고 
	// 싶었습니다.
	// => move 와 완벽한 전달 기술을 위해서
	// => "rvalue reference" 라는 문법 도입
	Point&& r4 = Point(1, 2); // ok. 
	
}





