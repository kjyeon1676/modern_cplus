// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

struct  Int32
{
	int value;
};

class Point
{
public:
	int x, y;
	Int32 i32;  

//	Point() {}
	Point() = default;

};

int main()
{	
	Point::InnerType pit;

	Point pt1;		// 모든 멤버(x,y)가 쓰레기값을 가지게 됩니다.
	Point pt2{};	// value initialization(내일 자세히..)
					// => 모든 멤버를 디폴트값(대부분 0)으로 초기화
					// => 단, 사용자가 생성자 구현을 제공하지 않을때

	std::cout << pt2.x << std::endl;
	std::cout << pt2.y << std::endl;
	std::cout << pt2.i32.value << std::endl;


}



