// 7_�����ڻ��1 - 26page
class Base
{
	int value;
public:
	Base()      : value(0) {}
	Base(int n) : value(n) {}
};
class Derived : public Base
{
public:
	// �����ڴ� �⺻������ ��� �ɼ� �����ϴ�.
	// C++11 ���� �Ʒ�ó�� �ϸ� �����ڵ� ��� �˴ϴ�.
	using Base::Base;
};

int main()
{
	// �Ʒ� 2���� ������ ������
	Derived d1;
	Derived d2(5);
}
