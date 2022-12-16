#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void Init(int a, int b)
	{
		printf("Dialog Init : %d, %d\n", a, b);
	}
};

int main()
{
	// C ����� �Լ� �����ʹ� �������� ���� �����մϴ�.
//  void(*f)(int) = &f1; // ok
//	f = &f2; // error. f2 �� ���ڰ� 2���Դϴ�.


	// C++11 ���� �߰��� std::function �� �Լ� ������ ����
	// �����ϴ�.
	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10)
    
}












