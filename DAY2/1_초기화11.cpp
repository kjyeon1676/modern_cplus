// 1_초기화11 - 65 page..
// aggregate initialization

// aggregate type
// => 생성자가 없어도 {}로 초기화가 가능한 타입
// => 배열, 구조체, union 등.

struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {}	// 사용자가 만든 생성자가 있으면 aggregate type 아닙니다.
	Point() = default;	// 이 코드는 있어도 aggregate type 입니다.

//	virtual void foo() {}	// 가상함수가 있으면 aggregate 아닙니다.
	void goo() {}			// 일반 멤버 함수가 있어도 aggregate 입니다.
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 }; 
	// => 1. 인자 2개 짜리 생성자를 호출하는 표기법도 되지만
	// => 2. C언어의 구조체 초기화 표기법이기도 합니다.
}