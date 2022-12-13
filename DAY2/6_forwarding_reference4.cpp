struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) {}
};

// ��� 1. call by value
// => Ư¡ : ���纻 ����
// void foo(Point pt) {}


// ��� 2. call by const lvalue reference
// => ���纻�� �������� ����
// => ������� �߰��ȴ�.
//void foo(const Point& pt) {}


//=========�Ʒ� ����� C++11 ==========================
// ��� 3. 2���� foo �Լ�����
// => ���纻�� �������� �ʰ�, 
// => ������� �߰����� ����. 
//void foo(Point&  pt) {}
//void foo(Point&& pt) {}

// ��� 4. ���3�� 2���Լ� �ϴ� ���� ������ ���
//        �Ǵ� Point �� �ƴ϶� ��� Ÿ�Կ� ���� �ʿ� �Ѱ��
//        "T&&" �� ����ϸ� �� ��� 3�� �ϼ��� �ڵ� ����.!
template<typename T> void foo(T&& pt) {}

int main()
{
	Point pt(0, 0);

	// foo �Լ��� lvalue �� rvalue�� ��� ������ �ʹ�.
	foo(pt);
	foo(Point(0,0));
}
