// �Ʒ� �ڵ尡 �� �������� ������ ������ ?
/*
class A
{
	int data;
public:
	void foo()
	{
		*data = 10;	// int Ÿ���� * �ϹǷ� error
	}
};
int main()
{
	A a;
}
*/
template<typename T>
class A
{
	T data;
public:
	void foo()
	{
		*data = 10;	
	}
};

int main()
{
	A<int>  a;
	a.foo();
}
// �ٽ� 
// �ν��Ͻ�ȭ      : ���ø����� ���� ���� C++ �Լ�/Ŭ������ ����� ����
// �������ν��Ͻ�ȭ : ���� ���ø��� �ν��Ͻ�ȭ�� �ȴٴ� ����