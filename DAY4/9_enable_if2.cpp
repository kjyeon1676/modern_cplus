#include <iostream>
#include <type_traits>

// 2 ������ �ִ� ������� ���ϴ� �Լ��� ������ ���ô�.
template<typename T> T gcd(T a, T b)
{
	static_assert(std::is_integral_v<T>,
						"Error T is not Integer");
	return 0;
}

int main()
{
	gcd(6, 9);
	gcd(3.1,  5.4);
}