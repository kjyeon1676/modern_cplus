#include <iostream>

void foo(int a) {}

int& goo(int& a) { a = 100; return a; }

// 반환 값도 완벽히 돌려 주려면 "decltype(auto)" 사용

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
