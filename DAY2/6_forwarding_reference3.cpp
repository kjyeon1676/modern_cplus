// 6_forwarding_reference1 - ���� ���� �߿�!!
void f1(int&  r) {}
void f2(int&& r) {}

// �Լ� ���ڷ�
// int& : int Ÿ���� lvalue �� �ްڴٴ� ��
// int&&: int Ÿ���� rvalue �� �ްڴٴ� ��
// 
// T& : ?


template<typename T> void f3(T& a)
{
}

int main()
{
	int n = 5;

	// 1. ����ڰ� Ÿ���� ��������� �����ϴ� ���
	f3<int>(? );	// T=?		T&=?		�������Լ�:f3(? a)
	f3<int&>(? );	// T=?		T&=?		�������Լ�:f3(? a)
	f3<int&&>(? );	// T=?		T&=?		�������Լ�:f3(? a)
}











template<typename T> void f4(T&& a)
{
}
