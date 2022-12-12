// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 아무일도 하지 않은 인자가 없는 생성자를 만드는 2가지 방법
	// Point() {}	// 1. 직접 사용자가 만드는 경우
					//    컴파일러가 구현을 내용을 알수 없습니다.

	Point() = default;	// 2. 컴파일러에게 만들어 달라고 요청
						//    컴파일러가 구현의 내용을 정확히 알게 됩니다.
						//	  최적화가 잘됩니다.
};

int main()
{
	Point p1;
	Point p2(1, 2);
}




