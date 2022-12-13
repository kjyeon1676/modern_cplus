// decltype Ÿ�� �߷� - 71page
int main()
{
	int n = 10;
	int& r = n;
	const int c = 10;
	int* p = &n;

	// decltype(exp) : ��ȣ ���� ǥ����(exp)�� ���� Ÿ���� ����
	// ��Ģ 1. () �ȿ� �ɺ��� �̸��� �ִ� ���
	// => �ش� �ɺ��� ������ ���� ������ Ÿ������ ����
	decltype(n) d1; // int d1;
	decltype(r) d2; // int& d2;		�ʱⰪ�� �����Ƿ� ������ ����
	decltype(c) d3; // const int d3;�ʱⰪ�� �����Ƿ� ������ ����
	decltype(p) d4; // int* d4;

	// auto vs decltype
	decltype(r) d5; // int& d5
	auto a = r;		// int  a		�캯�� ���� ����
}