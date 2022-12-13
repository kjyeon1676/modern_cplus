// 1_�ʱ�ȭ9. - 63 page
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
	Point p1(1);		// Point(int) ȣ��
	Point p2(1, 2);		// Point(int, int) ȣ��
	Point p3({ 1,2 });	// Point(std::initializer_list<int> e) ȣ��

	Point p4{ 1,2 };	// Point(std::initializer_list<int> e) ȣ��
					    // => �� �����ڰ� ���ٸ� Point(int, int) ȣ��.

//	Point p5(1, 2, 3);	// error. Point(int, int, int) �� �����ϴ�.

	Point p6{ 1, 2, 3 }; // ok. Point(std::initializer_list<int> e) ȣ��
	
	Point p7 = { 1,2,3 }; // ok.. ���� �ʱ�ȭ!

	// ��� : ���ڷ� std::initializer_list �� �޴� �����ڰ� �ִٸ�
	//        ������ ���ڷ� ��� ���� �����մϴ�.
	// => �׷��� STL �����̳ʸ� C++11 ���ʹ� �Ʒ� ó�� ��밡���մϴ�
	std::vector<int> v1{ 1,2,3,4,5 };
	std::vector<int> v2 = { 1,2,3,4,5 };
				// => vector(std::initializer_list<int>) ȣ��
}


