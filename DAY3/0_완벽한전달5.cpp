#include <iostream>

void hoo(int&& arg) {}
// 정리
// 완벽한 전달을 하려면
// 1. int& 와 int&& 버전의 함수를 각각 제공
// 2. int&& 버전은 인자를 rvalue 캐스팅한 후에 forwarding

template<typename F>
void chronometry(F f, int& arg)
{
	f(arg);
}

template<typename F>
void chronometry(F f, int&& arg)
{
	f(static_cast<int&&>(arg));
}


int main()
{
	hoo(10);

	chronometry(hoo, 10);
}
