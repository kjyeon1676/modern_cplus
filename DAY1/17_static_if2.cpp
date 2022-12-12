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

