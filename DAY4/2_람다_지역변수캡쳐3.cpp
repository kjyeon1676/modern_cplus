// 6_����_��������ĸ��1 - 146
#include <iostream>

int g = 10;

int main()
{
	int v1 = 10, v2 = 10;

	// [v1, v2] : capture by value
	// auto f1 = [v1, v2](int a) mutable { v1 = 100; return a + v1 + v2; };

	// [&v1, &v2] : capture by reference
	auto f2 = [&v1, &v2](int a) { v1 = 100; return a + v1 + v2; };

	f2(30); // v1=100 �ε�. �̶� v1 �� main �� ���������� ���� �����̹Ƿ�
			// �������� v1�� ������.

	std::cout << v1 << std::endl;

	std::cout << sizeof(f2) << std::endl; // 8





	/*
	// ���������� ĸ�������� ����
	// �����Ϸ��� �����ϴ� Ŭ����
	class CompilerGeneratedName
	{
		int& v1; // ĸ�ĵ� ���������� ���� �����ϱ� ����
		int& v2; // ��� ����Ÿ
	public:
		CompilerGeneratedName(int& a, int& b) : v1(a), v2(b) {}

		inline int operator()(int a) const
		{
			v1 = 100;	// ���������� v1 ��ü�� �����ϴ� ǥ��� �ƴ�.
						// v1�� ����Ű�� ������ ���� �����Ѱ�
						// �׷���, const ����Լ������� ���� ����.

			return a + v1 + v2;
		}
	};
	auto f2 = CompilerGeneratedName(v1, v2);
	*/
}





