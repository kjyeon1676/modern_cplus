// 1_�����������ø�1-1

// Ÿ�� ���ڰ� �Ѱ��� �Լ� ���ø�
// => ���ڰ� �Ѱ��� �Լ��� �����Ҷ� ����ϴ� Ʋ.. 
template<typename T> void foo(T arg)
{
}

// ���� ���� �Լ� ���ø�
// => ... �� ��ġ ��Ȯ�� �˾� �μ���..
// => ���ڰ� N���� �Լ��� �����Ҽ� �ִ� ���ø�
template<typename ... Types> void goo(Types ... arg)
{
}

int main()
{
	foo(1);		// foo(int) ����
	foo(3.4);	// foo(double) ����

	goo(1);      // goo(int)
	goo(3.4);	 // goo(double) ����
	goo(1, 3.4); // goo(int, double) ����
	goo();		 // goo() ����..
}