// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	auto f2 = [v1, v2](int a) { v1 = 100; return a + v1 + v2; }; 

	// ���������� ĸ�������� ����
	// �����Ϸ��� �����ϴ� Ŭ����
	class CompilerGeneratedName
	{
		int v1; // ĸ�ĵ� ���������� ���� �����ϱ� ����
		int v2; // ��� ����Ÿ
	public:
		CompilerGeneratedName(int a, int b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100;
			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName(v1, v2);
}





