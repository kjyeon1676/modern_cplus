#include <iostream>

void foo(int a) {}

int& goo(int& a) { a = 100; return a; }

// ��ȯ ���� �Ϻ��� ���� �ַ��� "decltype(auto)" ���

template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
	return f(std::forward<T>(arg));
}


int main()
{
	int n = 0;

	int& ret = chronometry(goo, n); // goo(n)
}
