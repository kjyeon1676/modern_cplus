// 20_Ÿ���߷�5

template<typename T> void foo(T a) {}

int main()
{
	// ���ø��� ȣ��� ������ ���ڷ� Ÿ�� �߷�
	foo(10);
	// T a = 10; // �ᱹ �� ǥ����� �˴ϴ�. 10���� T�� Ÿ���� ���� 
	auto a = 10; // �ᱹ �� ǥ����� T�� �ڸ��� auto �� ������ �Դϴ�.
				 // auto �� �߷� ��Ģ�� ���ø��� �����մϴ�!!




	int  n = 10;
	int& r = n;
	const int c = 10;
	const int& cr = c;

	// auto �߷��� ���ø� �߷а� �����մϴ�.
	// �Ʒ� �� ������ Ÿ���� ������ ������
	// auto a1 = n;
	// T    a1 = n;
	// �ᱹ ���ø� �Ķ���Ͱ� �� Ÿ���϶� �̹Ƿ� "��Ģ1" �Դϴ�.
	// => �Լ�����(�캯)�� ���� const, volatile, reference �� �����Ŀ�
	//    Ÿ�� ����. 
	// => �� ������ Ÿ���� ��Ȯ�� Ȯ���Ҽ� ������ ??
	//    => ���� ������ ����� �����ϴ�. �׷��� ���ø����� Ȯ���ϴ� ���� �����ϴ�.
	//    => ��, boost �� type_id_with_cvr �̶�� Ŭ������ Ȯ���� �����մϴ�.
	//    => typeid(a1).name()  �� ����� reference, const ���� ��¾ȵ˴ϴ�.
	// ��Ģ 1.
	auto a1 = n;  // int a1;
	auto a2 = r;  // int a2;
	auto a3 = c;  // int a3;
	auto a4 = cr; // int a4;

	// ��Ģ 2.
	// auto& a5 = n;
	// T&    a5 = �Լ�����; �� ���� �̹Ƿ� ��Ģ 2.
	// => �Լ�����(�캯)�� reference �� �����ϰ� auto Ÿ�� ����
	// => const, volatile �� ����
	auto& a5 = n;	// auto=int				a5=int&
	auto& a6 = r;	// auto=int				a6=int&
	auto& a7 = c;	// auto=const int		a7=const int&
	auto& a8 = cr;	// auto=const int		a8=const int&

	//��Ģ 3.
	auto&& a9 = 10; // �߿�.. ���Ŀ� ������!

}


