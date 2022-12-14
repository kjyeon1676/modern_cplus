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
	//std::shared_ptr<Point> sp1(new Point(1,2));

	// shared_ptr �� ����Ϸ��� "std::make_shared" �� ����ؼ� ������!!
	// ���� : sizeof(Point) + sizeof(������ü) ũ���� �޸𸮸�
	//       �ѹ��� �Ҵ��ؼ� �޸� ȿ������ ���� �Ѵ�.
	std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);
						// => sizeof(Point) + sizeof(������ü)�� �ѹ��� �Ҵ�
						// => Point ��ü�� 1, 2�� �ʱ�ȭ
						// => shared_ptr�� ����� ��ȯ

	// make_shared �� �ᱹ ���޹��� ���� 1,2 �� Point �����ڷ� �ٽ�
	// �����ؾ� �մϴ�.
	// 1, 2 =========> make_shared ==========> Point(int a, int b)
	// �Ϻ��� ���� ����� ������ �մϴ�.
}







