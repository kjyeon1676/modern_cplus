// 1_�ʱ�ȭ6 - 60 page
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
	// �ʱ�ȭ ����� ���
	int n1{ 0 };		// direct initialization
	int n2 = { 0 };		// copy initialization
	int n3;				// default initialization
	int n4{};			// value initialization
						// => int�� ����Ʈ���� 0���� �ʱ�ȭ �˴ϴ�.

	std::cout << n4 << std::endl; // 0

	Point pt{};		// ��� ����� 0���� �ʱ�ȭ �˴ϴ�.
					// => ��, ����ڰ� ������ �����ڰ� ������.
	std::cout << pt.x << std::endl;
}


