// new1
#include <iostream>

struct Point
{
	int x, y;
	
	Point(int a, int b) : x(a), y(b) {std::cout << "Point(int, int)" << std::endl;	}
	~Point(){ std::cout << "~Point(int, int)" << std::endl; }
};

int main()
{
	Point* p1 = new Point(1, 2);
	delete p1;
}