#include <iostream>

void foo(int* p) {}
void goo(char* p) {}

// nullptr �� ���� ����� ���ô�.

int main()
{
	foo(xnullptr);
	goo(xnullptr);
}