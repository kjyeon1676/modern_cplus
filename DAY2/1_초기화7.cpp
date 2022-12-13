
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

class Rect
{
	Point pt; // 핵심 : Point 는 디폴트 생성자가 없습니다.
public:
	// 사용자가 만든 생성자	// 컴파일러가 변경한 코드
	// Rect() {}			// Rect() : pt() {}		
							// => Point 의 디폴트 생성자 호출하는 코드생성

	// C++98 시절 해결책 : 멤버 데이타의 생성자를 명시적으로 호출하는
	//					  코드를 제공
	Rect() : pt(0, 0) {}
//	Rect() : pt{ 0, 0 } {}
};

// C++11 부터는 아래 처럼 해도 됩니다.
class Rect2
{
	Point pt{ 0, 0 }; // ok.. 
//	Point pt(0, 0); //error. 위처럼 {}로 하세요
public:
};


int main()
{
	Rect r1;
}

