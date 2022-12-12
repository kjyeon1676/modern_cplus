// 17_static_if - 51 page

template<typename T> void foo(T a)
{
	// if : ����ð� ���ǹ�
	//      �����϶� ���ǽ��� false �� �Ǿ
	//		if ���� ������ "���ø� �ν��Ͻ�ȭ�� ����" �˴ϴ�.
	//if (false)
	//	*a = 10;

	// if constexpr : ������ �ð� ���ǹ� ( C++17)
	//				  ���ǽ��� false ���
	//				  if ���� ������ "���ø� => C++ �Լ�"�� ���鶧
	//				  ���� �˴ϴ�.
	if constexpr (false)
		*a = 10;
}

int main()
{
	foo(0); 
}

void goo(int n)
{
//	if constexpr (n > 0) // error. ���ǽ��� ����� ������ �Ҷ�
//	{					// �˾ƾ� �մϴ�.
//	}
	int n = 0;
	if constexpr (sizeof(int*) >= 8)
	{
		x = 21;
		std::cout << "64bit" << std::endl;
	}
	else
	{
		x = 2;
		std::cout << "not 64bit" << std::endl;
	}
}
