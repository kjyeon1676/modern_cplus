#include <iostream>

// auto �� ���� ǥ����
int main()
{
//	Point pt = Point(1, 2);
			// 1. 1,2 �� �ʱ�ȭ�� �ӽð�ü�� �����..
			// 2. pt �� ����(��Ȯ���� move ������)�˴ϴ�.
			
			// �׷���, ���� ������(move ������)�� ���ŵǴ� ����ȭ��
			// ����˴ϴ�. ���� �� ������ �Ʒ� ���ٰ� ������ �����ϴ�.
//	Point pt(1, 2);
	//-------------------------------------------

	// �ٽ� 1. ����ǥ������ ���� ����� �ӽð�ü �Դϴ�.
	// �ٽ� 2. ����ǥ������ auto  ������ ��Ƽ� �Լ� ó�� ��밡���մϴ�.

	auto f = [](int a, int b) { return a + b; };
			// class xxx{ operator(){}}; xxx();
			// xxx f;

	int n1 = f(1, 2);
	int n2 = f.operator()(1, 2); // �̷��Ե� ��밡���մϴ�.

	// �ٽ� 3. ���� ǥ������ �ӽð�ü rvalue �Դϴ�.

	auto a1 = [](int a, int b) { return a + b; };

	auto& a2 = [](int a, int b) { return a + b; };
	
	const auto& a3 = [](int a, int b) { return a + b; };
	
	auto&& a4 = [](int a, int b) { return a + b; };
}

