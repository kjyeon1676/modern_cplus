#include <iostream>

int main()
{
	// �Ʒ� �ڵ��� ������ ()�����ڰ� ���ø��̰�
	// => "2���� ���ڰ� ���� �ٸ� ���ø�" �Դϴ�.
	auto f1 = [](auto a, auto b) { return a + b; };


	auto swap1 = [](auto& a, auto& b) { auto tmp = std::move(a);
										a = std::move(b);
										b = std::move(tmp); };

	int n = 10;
	double d = 3.4;

	swap1(n, d); // �Ǵ°��� ������� ? �ȵǴ°� ������� ?
				 // �ȵǴ� ���� �����ϴ�.  

	// C++20 ���ʹ� "template ���� ǥ����" �̶�� ���ο� ������ �Ұ��˴ϴ�
	auto swap2 = []<typename T>(T& a, T& b) { T tmp = std::move(a);
												a = std::move(b);
												b = std::move(tmp); };

	swap2(n, d); // error. ���� Ÿ���� �ƴմϴ�.
}

