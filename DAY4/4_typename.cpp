// 2_typename

struct Test
{
	static int data;
	typedef int DWORD; // using DWORD = int;
};
int Test::data = 0;
int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	// �Ʒ� �ڵ忡�� * �� �ǹ̸� ������ ������
//	Test::data  * p;	// ���ϱ��� �ǹ� ( 0 * 0 )
//	Test::DWORD * p; 	// ������ ���� p�� �����ϴ� ���
						// *�� �ǹ̴� ���ϱⰡ �ƴ϶� ������ ������

	// "Ŭ�����̸�::�̸�" �� ǥ������� "�̸�"�� �ǹ̴�
	// 1. �� �ϼ� �ְ�		: static ��� ����Ÿ, enum ���
	// 2. Ÿ�� �ϼ� �ֽ��ϴ�.	: typedef �Ǵ� using ��.. 

	// �Ʒ� �ڵ带 ������ ������.. 
	// �����̸�(dependent name)
	// => "T::�̸�" ó�� ���ø� ���ڿ� ������ �̸�
	// => �����Ϸ��� �⺻ ������ "�̸�"�� "������ �ؼ�"
	// => �����̸��� ���� �ƴ� Ÿ������ �ؼ��ǰ� �Ϸ��� typename �ʿ�
	T::data  * p;
	//T::DWORD * p; // error. �� VC��� ������ �߻����� ������ ������
					// C++ ������ ���� �Դϴ�.
	typename T::DWORD* p;

	return 0;
}





int main()
{
	Test t;
	foo(t);
}



