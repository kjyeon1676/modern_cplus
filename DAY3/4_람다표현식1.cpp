// 2_����ǥ����1 - 127 page

int add(int a, int b) { return a + b; }


// foo : ���ڷ� �Լ� ������(�ּ�)�� �䱸�մϴ�
void foo(  int(*f)(int, int) )
{
}

int main()
{
	foo(add); // ok 

	// ���� ǥ���� 
	// => �͸��� �Լ��� ����� ����
	// => �Լ��̸�(�ּ�)�� �ʿ��� ���� �Լ��� ������ü�� ����ϴ� ����

	// [] : lambda introducer. ���� ǥ������ ���۵��� �˸��� ��ȣ. 

	foo( [](int a, int b) { return a + b; } ); // ok 
}