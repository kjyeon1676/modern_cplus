#include <thread>
#include <memory>
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};
void* operator new(std::size_t sz)
{
	printf("new : %d\n", sz);
	return malloc(sz);
}

int main()
{
	// 스마트 포인터
	// 1. 직접 객체 생성
	// 아래 코드는 동적 메모리를 몇번 할당 할까요 ? 2번
	// 1. new Point
	// 2. shared_ptr 생성자에서 관리객체 생성
	//std::shared_ptr<Point> sp1(new Point(1,2));

	// shared_ptr 을 사용하려면 "std::make_shared" 를 사용해서 만들어라!!
	// 장점 : sizeof(Point) + sizeof(관리객체) 크기의 메모리를
	//       한번에 할당해서 메모리 효율성을 좋게 한다.
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);
						// => sizeof(Point) + sizeof(관리객체)를 한번에 할당
						// => Point 객체를 1, 2로 초기화
						// => shared_ptr을 만들어 반환

	// make_shared 도 결국 전달받은 인자 1,2 를 Point 생성자로 다시
	// 전달해야 합니다.
	// 1, 2 =========> make_shared ==========> Point(int a, int b)
	// 완벽한 전달 기술로 만들어야 합니다.
}







