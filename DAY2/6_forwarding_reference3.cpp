// 6_forwarding_reference1 - ���� ���� �߿�!!
void f1(int&  r) {}
void f2(int&& r) {}

// �Լ� ���ڷ�
// int& : int Ÿ���� lvalue �� �ްڴٴ� ��
// int&&: int Ÿ���� rvalue �� �ްڴٴ� ��
// 
// T& : ���� Ÿ���� lvalue �� �ްڴٴ� �ǹ�


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 5;

	// 1. ����ڰ� Ÿ���� ��������� �����ϴ� ���
	f3<int>(n );	// T=int	T&=int&		�������Լ�:f3(int& a)
	f3<int&>(n );	// T=int&	T&=int& &	�������Լ�:f3(int& a)
	f3<int&&>(n );	// T=int&&	T&=int&& &	�������Լ�:f3(int& a)

	// 2. ����ڰ� Ÿ���� �������� ������ 
	// => �����Ϸ��� �Լ� ���ڸ� ���� �Լ��� �����Ϸ��� ����մϴ�.
	f3(10);	// T=int, int&, int&& ������ �ص� ��� 10�� ������ ����
			// ������ ����!
	f3(n);	// T=int �� ����.!
}











template<typename T> void f4(T&& a)
{
}
