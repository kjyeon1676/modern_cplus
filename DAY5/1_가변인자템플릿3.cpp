#include <iostream>

int hoo(int a) { return -a; }

void goo(int a, int b, int c) {}

template<typename ... Types> void foo(Types ... args)
{
	// args : 1, 2, 3 이 있습니다.

//	goo(args); // error. pack 을 인자로 직접 사용할수 없습니다.



	// 핵심 1. Pack Expansion
	// "팩을사용하는 패턴" ...  => "E1패턴", "E2패턴", "E3패턴"

	goo(args...); // ok.. pack 의 모든 요소를 , 를 사용해서 열거해달라
				  // goo(1, 2, 3);

	goo((++args)...);	// goo(++E1, ++E2, ++E3 )
						// goo(++args...) 처럼 () 없어도 됩니다.
}


int main()
{
	foo(1, 2, 3);
}
