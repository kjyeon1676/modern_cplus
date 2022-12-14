// move �� ���� ����.. !
// ��������� ����� �ٽ� ������ ���ô�.
class Point
{
	int x, y;
public:
	Point() {}				// 1
	Point(int a, int b) {}	// 2

	// ���� �������� ����� ��Ȯ�� ������ ���ô�.
	// 1. call by value
	// => ���ڸ� ������ �ٽ� ���� �����ڰ� ȣ��Ǵ� ����
	// => ��, ���� �����ڰ� ������ ȣ��Ǵ� �ڵ�
	// => ������ ����. 
	//Point(Point pt) {}

	// 2. call by reference
	// => ������ ���.
	// => ������ rvalue �� ������ ����.
	// => ��Ÿ������ ��ȯ�ϴ� �Լ��� ���ϰ��� ������ ����
	// => Point ret = foo(); // error
	// Point(Point& pt) {}

	// ��� 3. const lvalue reference 
	// => lvalue �� rvalue �� ��� ������ �ִ�.
	Point(const Point& pt): x(pt.x), y(pt.y) {}
};

Point foo()
{
	Point pt(1, 2);
	return pt;
}
  
int main()
{
	Point p1;		
	Point p2(1, 2); 
	Point p3(p2);	// �����Ϸ��� ����� �ִ� ���� ������ ���		

	Point ret = foo(); //  Point ret( foo() );
}




