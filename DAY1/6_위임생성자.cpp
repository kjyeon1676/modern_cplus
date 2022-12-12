#include <iostream>
// 6_위임생성자 - 24page

class Base {};
 
class Point :public Base 
{
public:
	int x, y;
public:
	// C++11 부터 생성자에서 다른 생성자 호출이 가능합니다.
	// => 위임 생성자라고 합니다.
	// => 초기화 리스트에서 적어야 합니다.
	Point() : Point(0,0)
	{
	//	Point(0, 0); // 생성자에서 다른 생성자 호출 이 아닙니다.
					 // => 임시객체를 만드는 표기법입니다.
					 // => 내일 자세히 배웁니다.

	//	new(this) Point(0, 0); // placement new 라는 기술로 
								// 다른 생성자 호출 할수도 있지만..
								// 이 경우, 기반 클래스 생성자가 2번호출
								// 되는 문제가 발생합니다.
								// 반드시 위임생성자 문법을 사용하세요
	}
	Point(int a, int b) : x(a), y(b)
	{
		// 복잡한 초기화 코드
	}
};
int main()
{
	Point p;
	std::cout << p.x << std::endl;

}

