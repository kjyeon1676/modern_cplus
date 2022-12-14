// 8_완벽한전달활용
#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣기. 
	// 1. 객체를 만든후에 넣기
	// Point pt(1, 2);
	// v.push_back(pt);

	// 2. 임시객체로 넣기
	//v.push_back(Point(1, 2));

	// 3. 핵심.
	// => 객체를 만든후에 전달하지 말고
	// => 객체를 만들기 위한 생성자 인자를 전달
	v.emplace_back(1, 2);
			// => 1,2 를 받아서 내부적으로 new Point(1,2)로 생성
			// => emplace_back 은 결국 전달받은 인자값을 모두
			//    Point 생성자에 다시 전달해야 합니다
			//    완벽한 전달 기술을 사용해야 합니다.

	std::cout << "-----" << std::endl;
}

// 1, 2 ====> emplace_back  =========> Point 생성자

