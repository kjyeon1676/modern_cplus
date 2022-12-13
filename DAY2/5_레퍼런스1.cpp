// 3_레퍼런스1.cpp - 89 page - 아주 중요!

struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point pt(0, 0);

	// 규칙 1. non-const lvalue reference 는 lvalue 만 가리킬수 있다.
	Point& r1 = pt;			// ok
	Point& r2 = Point(0, 0);// error


	// 규칙 2. const lvalue reference 는 lvalue 와 rvalue를 모두 가리킬수 있다.
	const Point& r3 = pt;		  // ok
	const Point& r4 = Point(0, 0);// ok.


	// 규칙 3. C++11의 새로운 rvalue reference
	// => C++11 만들때 임시객체(rvalue)를 상수성없이 가르키고
	//    싶었다.(move와 완벽한 전달을 위해 )
	// => non-const rvalue reference 는 rvalue 만 가리킨다.
	Point&& r3 = pt;			// error
	Point&& r4 = Point(0, 0);	// ok


	// const rvalue reference 도 rvalue 만 가리킵니다.
	// => 그런데, 사용되지 않기 때문에 보통 별도로 언급하지는 않습니다.
	// const Point&& r3 = pt;			// error
	// const Point&& r4 = Point(0, 0);	// ok
}