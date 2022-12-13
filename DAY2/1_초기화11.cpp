// 1_�ʱ�ȭ11 - 65 page..
// aggregate initialization

// aggregate type
// => �����ڰ� ��� {}�� �ʱ�ȭ�� ������ Ÿ��
// => �迭, ����ü, union ��.

struct Point
{
	int x, y;

//	Point()             : x(0), y(0) {}	// 1
//	Point(int a, int b) : x(a), y(b) {}	// 2

//	Point() {}	// ����ڰ� ���� �����ڰ� ������ aggregate type �ƴմϴ�.
	Point() = default;	// �� �ڵ�� �־ aggregate type �Դϴ�.

//	virtual void foo() {}	// �����Լ��� ������ aggregate �ƴմϴ�.
	void goo() {}			// �Ϲ� ��� �Լ��� �־ aggregate �Դϴ�.
};

int main()
{
	Point p1;	
	Point p2 = { 1, 2 }; 
	// => 1. ���� 2�� ¥�� �����ڸ� ȣ���ϴ� ǥ����� ������
	// => 2. C����� ����ü �ʱ�ȭ ǥ����̱⵵ �մϴ�.
}