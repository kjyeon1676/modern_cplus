// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

struct  Int32
{
	int value;
};

class Point
{
public:
	int x, y;
	Int32 i32;  

//	Point() {}
	Point() = default;

};

int main()
{	
	Point::InnerType pit;

	Point pt1;		// ��� ���(x,y)�� �����Ⱚ�� ������ �˴ϴ�.
	Point pt2{};	// value initialization(���� �ڼ���..)
					// => ��� ����� ����Ʈ��(��κ� 0)���� �ʱ�ȭ
					// => ��, ����ڰ� ������ ������ �������� ������

	std::cout << pt2.x << std::endl;
	std::cout << pt2.y << std::endl;
	std::cout << pt2.i32.value << std::endl;


}



