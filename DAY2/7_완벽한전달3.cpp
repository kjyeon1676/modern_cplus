#include <iostream>

void hoo(int&& arg) {}

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	f(arg);
}

int main()
{
	hoo(10); // ok
	chronometry(hoo, 10); // error.. 왜??? 에러일까요 ?
						  // => "이유와 해결책은 4번" 에서
}
