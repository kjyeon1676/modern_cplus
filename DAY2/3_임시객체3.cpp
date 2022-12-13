// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 - 81 page
void foo(const Point& pt) {}

int main()
{
//	Point pt(1, 2);	// pt를 foo 에 전달하기 위해서만 만들었다면
//	foo(pt);		// 전달한 뒤에는 더이상 pt는 필요 없다.
					// 하지만 pt 는 이름이 있으므로 즉시 파괴될수없고
					// {}을 벗어날때 파괴 된다.

	// 핵심 1: 함수 인자로만 사용될 객체라면 임시객체(이름없는 객체)를
	// 사용하는 것이 효율적입니다.
	foo( Point(1, 2) );

	std::cout << "-----" << std::endl;
}

// 핵심 2. 함수 인자와 레퍼런스
// 함수 인자로 "non-const reference" 를 사용하는 경우
// => 전달된 객체를 수정하겠다는것
// => 임시객체를 전달할수 없다.!!
void init(Point& pt) { pt.x = 0; pt.y = 0; }

init(Point(1, 2)); // error 가 나와야 하고, error 입니다.


// 함수 인자로 "const reference" 를 사용하는 경우
// => 전달된 객체를 읽기만 하겠다는 의도
// => 임시객체를 전달할수 있어야 한다.
void drawLine(const Point& from, const Point& to) {} 

drawLine( Point(0, 0), Point(100, 100) ); // ok


// C++11 에서는 임시객체를 함수 로 전달하는데..
// "임시객체를 변경 해야 하는 경우가 생겼습니다." => move.. 시간에.. 




