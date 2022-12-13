// 1_초기화6 - 60 page
#include <iostream>

struct Point
{
	int x;
	int y;

//	Point() {}
	Point() = default;
};

int main()
{
	// 초기화 방법과 용어
	int n1{ 0 };		// direct initialization
	int n2 = { 0 };		// copy initialization
	int n3;				// default initialization
	int n4{};			// value initialization
						// => int의 디폴트값인 0으로 초기화 됩니다.

	std::cout << n4 << std::endl; // 0

	Point pt{};		// 모든 멤버가 0으로 초기화 됩니다.
					// => 단, 사용자가 제공한 생성자가 없을때.
	std::cout << pt.x << std::endl;
}


