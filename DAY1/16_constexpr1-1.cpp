// 16_constexpr1-1

int main()
{
	int n = 10;
	
	const int c1 = 10; // ok
	const int c2 = n;  // ok

	// C++11 constexpr : ������ �ð� ����� ����� Ű����
	constexpr int c3 = 10; // ok
	constexpr int c4 = n;  // error. ���������� �ʱ�ȭ �ȵ�


}