// 1_초기화9. - 63 page
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int)      { std::cout << "int" << std::endl;	}
	Point(int, int) { std::cout << "int, int" << std::endl; }
	Point(std::initializer_list<int> e) { std::cout << "initializer_list<int>" << std::endl; }
};
int main()
{
	Point p1(1);		// Point(int) 호출
	Point p2(1, 2);		// Point(int, int) 호출
	Point p3({ 1,2 });	// Point(std::initializer_list<int> e) 호출

	Point p4{ 1,2 };	// Point(std::initializer_list<int> e) 호출
					    // => 위 생성자가 없다면 Point(int, int) 호출.

//	Point p5(1, 2, 3);	// error. Point(int, int, int) 가 없습니다.

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int> e) 호출
	
	Point p7 = { 1,2,3 }; // ok.. 복사 초기화!

	// 결론 : 인자로 std::initializer_list 를 받는 생성자가 있다면
	//        생성자 인자로 몇개라도 전달 가능합니다.
	// => 그래서 STL 컨테이너를 C++11 부터는 아래 처럼 사용가능합니다
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };
				// => vector(std::initializer_list<int>) 호출
}


