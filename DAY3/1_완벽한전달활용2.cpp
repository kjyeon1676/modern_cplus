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
	// ����Ʈ ������
	// 1. ���� ��ü ����
	// �Ʒ� �ڵ�� ���� �޸𸮸� ��� �Ҵ� �ұ�� ? 2��
	// 1. new Point
	// 2. shared_ptr �����ڿ��� ������ü ����
	std::shared_ptr<Point> sp1(new Point(1,2));
}







