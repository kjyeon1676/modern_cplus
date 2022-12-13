// �Լ� ���ڷ�
// int& : int Ÿ���� lvalue �� �ްڴٴ� ��
// int&&: int Ÿ���� rvalue �� �ްڴٴ� ��
// 
// T& : ���� Ÿ���� lvalue �� �ްڴٴ� �ǹ�

// T&&  
// 1. ���� Ÿ���� lvalue, rvalue �� ��� �ްڴٴ� �ǹ�!
// 2. "��� �޴� �ٴ� �ǹ�" �� "������ �ִ� �Լ��� ����" �Ѵٴ°�
// 3. ������ �Լ��� ��� "call by reference" ��. 
// 4. lvalue �� rvalue ������ T�� T&&�� Ÿ���� �Ϻ��� �����ϰ� �ܿ��� �մϴ�.

// lvalue ���� : f4(n); // T=int&   T&&=int&     f4(int&)
// rvalue ���� : f4(5); // T=int    T&&=int&&    f4(int&&)


// int&  : lvalue reference
// int&& : rvalue reference
// T&    : lvalue reference
// T&&   : forwarding reference �� ���� �̸�
//         universal referfence �� ������ڰ� effective-C++å���� ����





template<typename T> void f4(T&& a)
{
}


int main()
{
	int n = 5;

	// 1. Ÿ���� ��������� �����ϴ� ���
	f4<int>(5 );	// T=int		T&&=int&&		�������Լ�:f4(int&&)
	f4<int&>(n);	// T=int&		T&&=int& &&		�������Լ�:f4(int&)
	f4<int&&>(5);   // T=int&&		T&&=int&& &&	�������Լ�:f4(int&&)

	// 2. Ÿ���� ��������� �������� ���� ���
	// => �Լ� ���ڸ� ����, �Լ��� �����Ҽ� �ֵ��� T�� Ÿ���� ����

	f4(n);	// T=int �� �����ϸ� f4(int&&) �Լ� �����ϹǷ� error
			// T=int&�� �����ϸ� f4(int&) �Լ� ����.. ok.. 
			// �׷��� �̼��� T=int&�� ����.  f4(int&) �Լ� ����

	f4(5);	// T=int �� ����, ������ �Լ���  f4(int&&) �Լ� ����
}