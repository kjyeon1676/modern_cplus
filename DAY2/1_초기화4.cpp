// 58 page
class Vector
{
	int sz;
public:
	// explicit ������ : ���� �ʱ�ȭ�� ����Ҽ� ����
	//					���� �ʱ�ȭ�� �����ϴ�.
	//				    C++98 ����
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} // Vector v = 10				  

int main()
{
	// �ٽ� 1. ���ڰ� �Ѱ��� �����ڰ� ������ �Ʒ��� ǥ����� �����մϴ�.
	Vector v1(10);		// C++98. direct initialization
	Vector v2 = 10;		// C++98. copy   initialization

	Vector v3{ 10 };	// C++11. direct initialization
	Vector v4 = { 10 }; // C++11. copy   initialization

	//----------------
	// �ٽ� 2. �Լ��� ���� ������ ���� �ʱ�ȭ �Դϴ�.
	foo(10); // ?
//	foo( Vector(10) ); // �ӽð�ü�� �����ų�
//	Vector v;
//	foo(v); // vector�� ���� �� ����..
			// Vector v = v; �̹Ƿ� ���� ������ ȣ��
			// ���� �����ڴ� ��κ� explicit �� �ƴմϴ�.
}







