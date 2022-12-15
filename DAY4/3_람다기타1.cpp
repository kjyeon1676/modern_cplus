#include <iostream>
// 7_���ٱ�Ÿ1 - 150
class Test
{
	int data = 0;
public:
	void foo()
	{
		// ��� ����Ÿ ĸ�� ?
		//auto f = [](int a) { return a + data; }; // error


		// auto f = [data](int a) { return a + data; }; // error
				// => data �� ��� ���� ����, ���������� �ƴմϴ�.


		// �ٽ� 1. this �� ĸ���ϸ� ��� ����Ÿ�� ���� �Ҽ��ֽ��ϴ�.
		// => ���� ĸ���Ѱ��� data �� �ƴ� this �ε�
		//    "this->data" ó�� ������� �ʰ�, "data" �θ� ����մϴ�.
		// => "data=0" ���� ������ �����մϴ�. ������ ����˴ϴ�.
		auto f = [this](int a) { data = 15; return a + data; }; // ok

		f(0);

		std::cout << data << std::endl; // 15


		// C++17 ���� *this ĸ�ĵ� ���� �մϴ�.
		// => �� ���� "data=15" ó�� �����Ϸ��� �ϸ� ���� �Դϴ�.
		auto f2 = [*this](int a) { //data = 15; 
									return a + data; }; 
	}
};

int main()
{
	Test t;
	t.foo(); 
}

