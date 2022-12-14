// move 를 배우기 전에.. !
// 복사생성자 모양을 다시 생각해 봅시다.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// 복사 생성자의 모양을 정확히 이해해 봅시다.
	// 1. call by value
	// => 인자를 받을때 다시 복사 생성자가 호출되는 형태
	// => 즉, 복사 생성자가 무한히 호출되는 코드
	// => 컴파일 에러. 
	//Point(Point pt) {}

	// 2. call by reference
	// => 가능한 모양.
	// => 하지만 rvalue 를 받을수 없다.
	// => 값타입으로 반환하는 함수의 리턴값을 받을수 없다
	// => Point ret = foo(); // error
	// Point(Point& pt) {}

	// 방법 3. const lvalue reference 
	// => lvalue 과 rvalue 를 모두 받을수 있다.
	Point(const Point& pt): x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
  
int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);	// 컴파일러가 만들어 주는 복사 생성자 사용		

	Point ret = foo(); //  Point ret( foo() );
}




