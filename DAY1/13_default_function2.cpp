// 13_default_function - 41 page
#include <type_traits>
#include <iostream>

class Point
{
public:
	int x, y;

//	Point() {}
	Point() = default;
};

int main()
{	
	Point pt1;		// ��� ���(x,y)�� �����Ⱚ�� ������ �˴ϴ�.
	Point pt2{};	// value initialization(���� �ڼ���..)
					// => ��� ����� 0���� �ʱ�ȭ
					// => ��, ����ڰ� ������ ������ �������� ������

	std::cout << pt2.x << std::endl;
	std::cout << pt2.y << std::endl;


}



