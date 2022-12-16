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
	// => std::bind() ����� �����Ҽ� �ֽ��ϴ�.
	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10)

	f = std::bind(&f2, 5, _1);
	f(10); // f2(5, 10)

	f = std::bind(&f4, 6, 3, _1, 9 );
	f(10); // f4(6, 3, 10, 9); ó�� �����ϰ� �غ�����.
    
	// f���� ��� �Լ��� ������ �ֽ��ϴ�.
	// ��, ��� �Լ��� ȣ��� ��ü�� �ʿ��ϹǷ�, ��ü�� �����Ǿ���մϴ�.
	Dialog dlg;
	f = std::bind(&Dialog::Init, &dlg, 3, _1);
	f(5); // dlg.Init(3, 5);
}











