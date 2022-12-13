
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

class Rect
{
	Point pt; // �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
public:
	// ����ڰ� ���� ������	// �����Ϸ��� ������ �ڵ�
	// Rect() {}			// Rect() : pt() {}		
							// => Point �� ����Ʈ ������ ȣ���ϴ� �ڵ����

	// C++98 ���� �ذ�å : ��� ����Ÿ�� �����ڸ� ��������� ȣ���ϴ�
	//					  �ڵ带 ����
	Rect() : pt(0, 0) {}
//	Rect() : pt{ 0, 0 } {}
};

// C++11 ���ʹ� �Ʒ� ó�� �ص� �˴ϴ�.
class Rect2
{
	Point pt{ 0, 0 }; // ok.. 
//	Point pt(0, 0); //error. ��ó�� {}�� �ϼ���
public:
};


int main()
{
	Rect r1;
}

