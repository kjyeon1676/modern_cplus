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
	// C 언어의 함수 포인터는 유연성이 많이 부족합니다.
//  void(*f)(int) = &f1; // ok
//	f = &f2; // error. f2 는 인자가 2개입니다.


	// C++11 에서 추가된 std::function 이 함수 포인터 보다
	// 좋습니다.
	std::function<void(int)> f;

	f = &f1;
	f(10); // f1(10)
    
}












