struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// 방법 1. call by value
// => 특징 : 복사본 생성
// void foo(Point pt) {}


// 방법 2. call by const lvalue reference
// => 복사본이 생성되지 않음
// => 상수성이 추가된다.
//void foo(const Point& pt) {}


//=========아래 방법은 C++11 ==========================
// 방법 3. 2개의 foo 함수제공
// => 복사본도 생성되지 않고, 
// => 상수성도 추가되지 않음. 
//void foo(Point&  pt) {}
//void foo(Point&& pt) {}

// 방법 4. 방법3의 2개함수 하는 일이 유사한 경우
//        또는 Point 뿐 아니라 모든 타입에 대해 필요 한경우
//        "T&&" 를 사용하면 위 방법 3의 하수를 자동 생성.!
template<typename T> void foo(T&& pt) {}

int main()
{
	Point pt(0, 0);

	// foo 함수에 lvalue 와 rvalue를 모두 보내고 싶다.
	foo(pt);
	foo(Point(0,0));
}
