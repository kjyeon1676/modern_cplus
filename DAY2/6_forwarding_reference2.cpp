// 91 page
int main()
{
	int n = 10;

	// �ٽ� 1. �������� �����͸� ����� �ֽ��ϴ�.
	int *p = &n;
	int* *pp = &p; // ok.. ���� ������

	// �ٽ� 2. reference �� ����Ű�� reference �� �ڵ�� ����
	//		   ����� �����ϴ�.
	int& r = n;
	int& &rr = r;	// error.


	using LREF = int&; 
	using RREF = int&&;

	// �ٽ� 3. Ÿ�� �߷� �������� �߻��Ǵ� reference �浹��
	//         ������ �ƴ϶� �Ʒ� ��Ģ���� Ÿ���� �����˴ϴ�.
	// reference collapsing
	LREF& r3 = n ;	// int&  &	=> int&
	RREF& r4 = n ;  // int&& &	=> int&
	LREF&& r5 = n ; // int&  && => int&
	RREF&& r6 = 10; // int&& && => int&&
}

template<typename T> void foo(T a)
{
	T& r = a;	// int& & r = a
				// int& r = a;
}

int n = 0;
foo<int&>(n);




