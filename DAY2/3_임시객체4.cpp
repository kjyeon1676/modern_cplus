// 3_임시객체1 - 77 page
#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};
// 임시객체와 함수 반환값 -  82 page
/*
void f1(Point  pt) {} // call by value     : 복사본 객체 생성
void f2(Point& pt) {} // call by reference : 복사본 객체 생성 안됨

int main()
{
	Point p(0, 0);
	f1(p);
	f2(p);
}
*/
//============================================


Point pt(1, 2);

Point foo()		// return by value
{
	return pt;	// pt를 복사해서 리턴용 임시객체 생성후
				// 임시객체 반환
}
Point& goo()	// return by reference
{		
	return pt;	// pt의 복사본을 만들지 말고..
}				// pt자체를 반환해 달라.!

int main()
{
//	foo().x = 10;	// error. "임시객체.x = 10" 의 의미.
	goo().x = 10;   // ok...  "pt.x = 10"
}

Point& hoo()
{
	Point p(1, 2);
	return p;	// 주의!!
				// 절대 지역변수는 참조 반환하면 안됩니다.
				// 값 반환만 사용해야 합니다.
}






