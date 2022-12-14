// 9_�Ϻ�������_���ǻ���3

// forwarding reference �̾߱�

template<typename T> class Test
{
public:
	// �Ʒ� �Լ� ���ڴ� "forwarding reference" �ϱ�� ?
	// �Ʒ� �Լ��� �Լ� ���ø��� �ƴմϴ�.
	// Ŭ���� ���ø��� �Ϲ� ��� �Լ� �Դϴ�.
	void foo(T&& arg)
	{
	}
	// ��� : forwarding reference �� �Ƿ��� �Լ� ��ü�� 
	//        ���ø� �̾�� �մϴ�.
	template<typename U>
	void goo(U&& arg)
	{
	}
};
int main()
{
	int n = 0;
	Test<int> t;	// �̼��� T=int�� �����Ǿ���
					// foo(int&&){} ������� �����Ǿ����ϴ�.
	
	// �Ʒ� �ڵ带 �����غ�����. ������ ������� ?
	t.foo(n);  // error
	t.foo(10); // ok
	
	t.goo(n);	// ok
	t.goo(10);	// ok
}
