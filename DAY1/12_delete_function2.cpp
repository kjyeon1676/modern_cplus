class Point
{
	int x, y;
public:
	Point() {}
	Point(int a, int b) {}

	// ����ڰ� ���� �����ڸ� ������ ������ �����Ϸ��� �����մϴ�.
	// �����Ϸ��� ���� �����ڸ� ������ �ʰ� �Ϸ���
	// ���� �����ڸ� �����ϸ� �˴ϴ�.
	// => �̱��� ���� ������ ���Ͽ��� �θ� ���
	// => std::unique_ptr ���� ����Ʈ �����Ͱ� ���� ���� ����Ʈ ������
	Point(const Point&) = delete;
};
int main()
{
	Point p1;
	Point p2(1, 2);

	Point p3(p2); // �� �ڵ尡 �� ������ ������ ?
				  // �����Ϸ��� ������ִ� ��������ڻ��
}