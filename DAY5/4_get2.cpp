#include <iostream>

template<typename ... Types>
struct tuple
{
	static constexpr int N = 0;
};

template<typename T, typename ... Types>
struct tuple<T, Types...> : public tuple< Types...>
{
	using base = tuple< Types...>;

	T value;

	tuple() = default;
	tuple(const T& n, const Types& ... args)
		: value(n), base(args...) {}

	static constexpr int N = base::N + 1;
};

int main()
{
//	tuple<>
//	tuple<		       short>					// 2 보관
//	tuple<	   double, short>					// 3.4 보관
	tuple<int, double, short> t3(1, 3.4, 2);	// 1 보관

	std::cout << t3.value << std::endl; // 1

	std::cout << t3.value << std::endl; // 3.4 나오게 해보세요

	std::cout << t3.value << std::endl; // 2 나오게 해보세요.
}











