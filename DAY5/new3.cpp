// new1
#include <iostream>

struct Point
{
	int x, y;

	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
	~Point() { std::cout << "~Point(int, int)" << std::endl; }
};

int main()
{
	// 3��¥�� ���۸� ����߽��ϴ�.
	Point* buff = new Point[3];

	// �׷��� 5���� ���۸� Ű���� �մϴ�.
	// => �Ʒ� ó�� �ϸ� ���ο� ������ 5�� ��ü�� ���� �����ڰ� ȣ��˴ϴ�.
	// => ������, ���� ���۸� �����ϸ� �ǹǷ� ������ ȣ���� �ʿ� ����.
	// Point* temp = new Point[5]; // bad!!!! 

	Point* temp = static_cast<Point>(operator new(sizeof(Point) * 5));

	// ���� 3���� ���� ������ ��ü�� ����(�̵�)�����ϸ� �˴ϴ�.
	for (int i = 0; i < 3; i++)
	{
	//	new(&temp[i]) Point;			// ����Ʈ ������
	//	new(&temp[i]) Point(buff[i]);	// ���� ������
	//	new(&temp[i]) Point(std::move(buff[i]));	// move ������
		new(&temp[i]) Point(std::move_if_noexcept(buff[i])); // move ������
	}

	// ���ο� 2���� ����Ʈ �����ڷ� �ʱ�ȭ
	for (int i = 3; i < 5; i++)
	{
		new(&temp[i]) Point;
	}

	// ���� �������� - ���� ���۴� new�� �����Ƿ� delete ���
	delete[] buff;

	buff = temp;
}



