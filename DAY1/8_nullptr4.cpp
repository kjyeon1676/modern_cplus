#include <iostream>

void foo(int* p) {}
void goo(char* p) {}

// nullptr 을 직접 만들어 봅시다.

int main()
{
	foo(xnullptr);
	goo(xnullptr);
}