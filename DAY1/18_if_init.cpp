// 18_if_init    50 page

int foo() { return 100; }

int main()
{
	int ret = foo();
	if (ret == 0)
	{
	}
	
	// C++17 �� ���ο� if�� 
	// => �ʱ�ȭ ������ ���� if ��
	// => if ( init; condition) {}
	if ( int ret2 = foo(); ret2 == 0 )
	{

	}	// <= ret2 �ı�

	// switch ���� �ʱ�ȭ ������ ������ �ֽ��ϴ�.
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}

	// while �� �ɱ�� ? => �����ϴ�. �ʿ��ϸ� for �� ����ϸ�˴ϴ�.
//	while (int cnt = 0; cnt < 9)
//	{
//	}
}