#include <iostream>
#include <thread> 

void foo(int n, double d)
{
	std::cout << "foo" << std::endl;
}

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

int main()
{
	// �����带 �����ϴ� ���

	std::thread t1(&foo, 3, 3.4);

	// �����带 ������ ���
	t1.join();   // 1. ���Ḧ ����ϰų�
//	t1.detach(); // 2. �ڽĽ����带 �и��ؾ� �մϴ�.

	// ��� ������ �Լ��� ������� �����Ҽ� �ֽ��ϴ�.
	Test test;
	std::thread t2(&Test::goo, &test, 1, 3.4);

	t2.join();
}


