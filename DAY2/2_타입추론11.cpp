int main()
{
	int x[3] = { 1,2,3 };

	auto a = x[0];		// int a;
	decltype(x[0]) d;	// int& d;


	// �迭�� Ÿ�� �߷�
	// ���� x�� Ÿ���� "int[3]" �Դϴ�.

	auto a1 = x;	// 1. int a1[3] = x; �� �߷�, �׷���, ����
					// 2. int* a1 = x; �� �߷��ϸ� ���� �ƴ�. 
					// ���� 2��.  ����
					// auto : int*

	auto& a2 = x;	// int(&a2)[3] = x; �� �߷еǴµ�. ���� �ƴ�.
					// ���� �� ���
					// auto : int[3];
					// a2   : int(&)[3]

	decltype(x) d; // int d[3]; ...  ok.. 
}

